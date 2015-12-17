#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

FILE * f;

typedef struct node node;

typedef struct hash_table hash_table;

const char for_scanf[255] = "%[\] !/\"#$\%&\'()*+,\n-.:;<=>\?@\\^_`{|}~0-9\[]%[A-Za-z]";

struct node {
    char key[255];
    int data;
    node * next;
};

struct hash_table {
    int size;
    node ** table;
};

void freeList(node* head){
    node *n = head;
    while (n) {
        node *tmp = n;
        n = n->next;
        free(tmp);
    }
}

node* getNode(node* next,const char * key, int val) {
    node* n = (node*)malloc(sizeof(node));
    if (n) {
        n->data = val;
        strcpy(n->key, key);
        n->next = next;
        return n;
    } else {
        return 0;
    }
}

void erase(node** h, char * key) {
    node * head = (*h);
    if (!strcmp((**h).key, key)) {
        (*h) = (**h).next;
        return;
    }
    node* prev;
    while(head) {
        if (!strcmp(head->key, key)) {
            prev->next = head->next;
            free(head);
            return;
        }
        prev = head;
        head = head->next;
    }
}

void printList(node* head) {
    while(head) {
        printf("%s %d \n", head->key, head->data);
        head = head->next;
   }
}

hash_table * create(int size) {
    hash_table * hashtable = malloc(sizeof(hash_table));
    if (hashtable == NULL) {
        return NULL;
    }
    hashtable->table = malloc(sizeof(node*) * size);
    if (hashtable->table == NULL) {
        free(hashtable);
        return NULL;
    }
    int i;
    for(i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }
    hashtable->size = size;
    return hashtable;
}

unsigned int hash37(hash_table * hashtable, char * str) {
    unsigned int hash = 0;
    for (; *str; str++) {
        hash = 37 * hash + *str;
    }
    return hash % hashtable->size;
}

unsigned int sum_symbol(hash_table * hashtable, char * str) {
    unsigned int hash = 0;
    for (;*str;str++) {
        hash += *str;
    }
    return hash % hashtable->size;
}

void set(hash_table * hashtable, char * key,int val, int (*hash)(hash_table *, char *)) {
    int hs = hash(hashtable, key);
    if (hashtable->table[hs] == NULL) {
        hashtable->table[hs] = getNode(hashtable->table[hs], key, val);
    } else {
        node * tmp = hashtable->table[hs];
        while (tmp) {
            if (!strcmp(key, tmp->key)) {
                tmp->data = val;
                return;
            }
            tmp = tmp->next;
        }
        hashtable->table[hs] = getNode(hashtable->table[hs], key, val);
    }
}

int get(hash_table * hashtable,char * key, int (*hash)(hash_table *, char *)) {
    int hs = hash(hashtable, key);
    if (hashtable->table[hs] == NULL) {
        return 0;
    } else {
        node * tmp = hashtable->table[hs];
        while (tmp) {
            if (!strcmp(key, tmp->key)) {
                return tmp->data;
            }
            tmp = tmp->next;
        }
        return 0;
    }

}

void delete_element (hash_table * hashtable,char * key, int (*hash)(hash_table *, char *)) {
    int hs = hash(hashtable, key);
    if (hashtable->table[hs] != NULL) {
        erase(&hashtable->table[hs], key);
    }
}

void print_count_word(hash_table * hashtable) {
    int i;
    for (i = 0; i < hashtable->size; i++) {
        if (hashtable->table[i] != NULL) {
            printList(hashtable->table[i]);
        }
    }
}

void hashtable_stat(hash_table * hashtable) {
    int count_noempty_cells = 0;
    int count_elements = 0;
    int count_words = 0;
    int min_length = 1e6;
    int max_length = 0;
    int often = 0;
    char often_key[80];
    int i;
    for (i = 0; i < hashtable->size; i++) {
        node * tmp = hashtable->table[i];
        if (tmp != NULL) {
            count_noempty_cells++;
            int k = 0;
            while (tmp) {
                k++;
                count_words += tmp->data;
                if (tmp->data > often) {
                    often = tmp->data;
                    strcpy(often_key, tmp->key);
                }
                count_elements++;
                tmp = tmp->next;
            }
            if (min_length > k) {
                min_length = k;
            }
            if (max_length < k) {
                max_length = k;
            }
        }
    }
    printf("Count no empty cells: %d\n", count_noempty_cells);
    printf("Count elements: %d\n", count_elements);
    printf("Count words all: %d\n", count_words);
    printf("Average chain length: %.1f\n", ((double)count_elements) / count_noempty_cells);
    printf("Min lenght chain: %d\n", min_length);
    printf("Max length chain: %d\n", max_length);
    printf("Most frequent count word: \"%s\" %d occurencies\n", often_key, often);
}

void delete_hashtable(hash_table * hashtable) {
    int i;
    for (i = 0; i < hashtable->size; i++) {
        freeList(hashtable->table[i]);
    }
    free(hashtable->table);
    free(hashtable);
}

int input_next_word(char * str) {
    char trash[255];
    if (fscanf(f, for_scanf, trash, str) != EOF){
        if (!strcmp(str, "")) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main(void) {
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return 0;
    }
    const int SIZE_TABLE = (int)1;
    hash_table * hashtable = create(SIZE_TABLE);
    if (hashtable == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }
    clock_t start_time = clock();
    char str[80];
    while (input_next_word(str)) {
        int i = 0;
        while (str[i]) {
            str[i] = tolower(str[i]);
            i++;
        }
        set(hashtable, str, get(hashtable, str, hash37) + 1, hash37);
        strcpy(str, "");
    }
    hashtable_stat(hashtable);
    clock_t finish_time = clock();
    printf("work time:%f\n", (double) (finish_time - start_time) / CLOCKS_PER_SEC);
    fclose(f);
    return 0;
}

