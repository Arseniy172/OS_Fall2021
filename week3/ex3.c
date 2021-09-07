#include<stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void print_list(struct Node* node){
    while (node != NULL) {
        printf(" %d ", node->value);
        node = node->next;
    }
}

void insert_node(struct Node** node, int value){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last_node = *node;
    new_node->next = NULL;
    new_node->value  = value;
    if (*node == NULL){
       *node = new_node;
       return;
    } 
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = new_node;
    return;  
}

void delete_node(struct Node** node, int value){
   struct Node *temp_node = *node, *previous;
    if (temp_node != NULL && temp_node->value == value) {
        *node = temp_node->next;
        free(temp_node);
        return;
    }
    while (temp_node != NULL && temp_node->value != value) {
        previous = temp_node;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL)
        return;
    previous->next = temp_node->next;
    free(temp_node);
}

int main(){
    struct Node* head = NULL;
    insert_node(&head,1);
    insert_node(&head,10);
    insert_node(&head,12);
    insert_node(&head,9);
    delete_node(&head, 12);
    insert_node(&head,4);

    print_list(head);
    return 0;
}