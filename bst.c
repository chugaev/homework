#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node* right;
    node* left;
};

node* create(int value) {
    node* tmp = (node*)malloc(sizeof(node));
    if (tmp == NULL) {
        return 0;
    }
    tmp->data = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


node* insert(node* tree, int value) {
   if (tree == NULL) {
        return create(value);
   } else if (tree->data < value) {
       tree->right = insert(tree->right, value);
   } else if (tree->data > value) {
       tree->left = insert(tree->left, value);
   }
   return tree;
}

int min(node* tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}

int find(node* tree, int value) {
    if (tree->data == value) {
        return 1;
    } else {
        if (tree->data > value) {
            if (tree->left) {
                find(tree->left, value);
            } else {
                return 0;
            }
        } else if (tree->data < value){
            if (tree->right) {
                find(tree->right, value);
            } else {
                return 0;
            }
        }
    }
}

node* rem(node* tree, int value) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->data < value) {
        tree->right = rem(tree->right, value);
    } else if (tree->data > value) {
        tree->left = rem(tree->left, value);
    } else {
        if ((tree->right) && (tree->left)) {
            node* right_min = min(tree->right);
            tree->data = right_min->data;
            tree->right = rem(tree->right,right_min->data);
            return tree;
        } else if (tree->right) {
            node* cur = tree->right;
            free(tree);
            return cur;
        } else if (tree->left) {
            node* cur = tree->left;
            free(tree);
            return cur;
        } else {
            free (tree);
            return NULL;
        }
    }
    return tree;
}

void print(node* tree) {
    if (tree == NULL) {
        return;
    }
    if (tree) {
        printf("(%d ",tree->data);
    }
    if (tree->left) {
        print(tree->left);
    } else {
        printf("null");
    }
    printf(" ");
    if (tree->right) {
        print(tree->right);
        printf(")");
    } else {
        printf(" null)");
    }
}

void print_mintomax(node* tree) {
    if (tree == NULL) {
        return;
    }
    print_mintomax(tree->left);
    printf("%d\n", tree->data);
    print_mintomax(tree->right);
}

void print_maxtomin(node* tree) {
    if (tree == NULL) {
        return;
    }
    print_maxtomin(tree->right);
    printf("%d ", tree->data);
    print_maxtomin(tree->left);
}

void free_tree(node* tree) {
    if (tree) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

int main(void) {

    return 0;
}

