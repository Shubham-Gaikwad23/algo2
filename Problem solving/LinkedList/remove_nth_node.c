// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* cur;
    struct ListNode* stopper;
    struct ListNode* tmp;
    int i, total_nodes;
    
    // Manually handle case for list of size less than or equal to 1
    if(head==NULL)
        return head;
    else if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    
    // Set stopper 'n' nodes ahead of head of the list
    for(i=0, stopper=head; i<n; ++i, stopper = stopper->next);
    
    // If stopper became 'NULL' then we need to delete first node
    if(stopper==NULL) {
        tmp = head;
        head = head->next;
        free(tmp);   
    }
    else {
        // Set 'cur' node to head
        // Keep moving 'stopper' and 'cur' node one node ahead of themselves
        // Until end of list is reached
        for(cur=head; stopper->next!=NULL; cur=cur->next, stopper=stopper->next);

        // Now 'cur' is just behind the node to be deleted and 'stopper' is at last node of the list
        tmp = cur->next;
        cur->next = cur->next->next;
        free(tmp);
    }
    
    return head;    
}
