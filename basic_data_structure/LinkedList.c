// 建立Llinked-list

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    
    int data;
    struct node *next;
}Node;

void AddNode(Node **start, int value){
    
    Node *new_Node = (Node*)malloc(sizeof(Node));
    new_Node->data = value;
    new_Node->next = NULL;
    
    if (*start==NULL){
        *start = new_Node;
    }
    else {
        Node *current;
        current = *start;
        while(current->next !=NULL){
            current = current->next;
        }
        current->next = new_Node;
    }
}

void print_List(Node *node){
    
    while(node !=NULL ){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void free_List(Node *node){
    
    Node *current, *tmp;
    current = node;
    while(current !=NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main()
{
    Node *head = NULL;
    AddNode(&head, 12);
    AddNode(&head, 156);
    AddNode(&head, 68);
    
    print_List(head);
    free_List(head);

    return 0;
}
