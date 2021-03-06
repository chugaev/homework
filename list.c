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

int main() {
    node *cur = 0;
    for(;;) {
        char ch;
        scanf("%c", &ch);
        if(ch == 'a') {
            int x;
            scanf("%d", &x);
            cur = getNode(x, cur);
        } else if(ch == 'r') {
            int x;
            scanf("%d", &x);
            erase(&cur, x);
        } else if(ch == 'p') {
            printList(cur);
        } else if(ch == 'q') {
            freeList(cur);
            return 0;
        }
    }
    return 0;
}

