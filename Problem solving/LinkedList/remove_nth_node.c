// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode *);

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* cur;
    struct ListNode* tmp;
    int i;
    
    if(head==NULL)
        return head;
    else if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    
    head = reverse(head);
    
    for(i=0, cur=head; i<n-2; cur=cur->next, ++i);
    if(n-2 == -1) {
        tmp = head->next;
        free(head);
        head = tmp;   
    }
    else {
        tmp = cur->next;
        cur->next = cur->next->next;
        free(tmp);
    }
    
    head = reverse(head);
    
    return head;    
}

struct ListNode* reverse(struct ListNode *head) {
    struct ListNode* left;
    struct ListNode* cur;
    struct ListNode* right;
        
    if(head == NULL || head->next == NULL)
        return head;
    
    for(left=NULL, cur=head, right=cur->next; cur!=NULL; ) {
        cur->next = left;
        
        left=cur;
        cur=right;
        if(right)
            right=right->next;
    }
        
    
    return left;
}
