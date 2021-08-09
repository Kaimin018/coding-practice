//leetcode-138
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    
    struct Node* cur = head;
    while (cur){
        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;
        NewNode->val = cur->val;
        cur->next = NewNode;
        NewNode->next = next;
        cur = next;
    }
    
    //處理random node
    cur=head;
    while (cur){
        struct Node* NewNode=cur->next;
        if(cur->random==NULL){
            NewNode->random=NULL;
        }
        else{
            NewNode->random=cur->random->next;
        }
        cur=NewNode->next;
    }
    cur=head;
    struct Node* newhead=NULL,* newtail=NULL;
    while (cur){
        struct Node* NewNode=cur->next;
        struct Node* next=NewNode->next;
        cur->next=NewNode->next;
        if(newtail==NULL){
           newhead=newtail=NewNode;
        }
        else{
           newtail->next=NewNode;
           newtail=NewNode;
        }
        cur=next;
    }
    
    return newhead;
	
}