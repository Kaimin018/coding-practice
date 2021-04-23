/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//leetcode-206 Reverse Linked List

struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    
    while(curr){
        struct ListNode *nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
    }
    return prev;

}