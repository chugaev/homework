#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node {
    int data;
    node * next;
};

void freeList(node* head){
    node *n = head;
    while (n) {
        node *tmp = n;
        n = n->next;
        free(tmp);
    }
}

node* getNode(int val, node* next) {
    node* n = (node*)malloc(sizeof(node));
    if (n) {
        n->data = val;
        n->next = next;
        return n;
    } else {
        return 0;
    }
}

void erase(node** h, int val) {
    node * head = (*h);
    if ((**h).data == val) {
        (*h) = (**h).next;
        return;
    }
    node* prev;
    while(head) {
        if(head->data == val) {
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
        printf("%d ", head->data);
        head = head->next;
   }
   printf("\n");
}

node* create_cicle() {
    const int SIZE_LIST = 10;
    node * n = (node*)malloc(sizeof(node));
    node * tmp = n;
    if(n) {
        int i;
        for(i = 1; i <= SIZE_LIST; i++) {
            n->data = i;
            n->next = (node*)malloc(sizeof(node));
            n = n->next;
        }
        n->next = tmp->next->next->next->next->next;
        return tmp;
    } else {
        return 0;
    }
}

int isCycle(node *head) {
    node * fast = head;
    node * slow = head;
    while(1) {
        if(fast == NULL) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
        if(fast == slow) {
            return 1;
        }
    }
}

int main() {
    node *cur = 0;
    cur  = create_cicle();
    printf("%d\n", isCycle(cur));
    return 0;
}

