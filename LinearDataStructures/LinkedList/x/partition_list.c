// https://leetcode.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* append(struct ListNode*, int);
struct ListNode* create(int);

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* lesser;
    struct ListNode* greater; 
    struct ListNode* curr;
    struct ListNode* less_tail; 
    struct ListNode* great_tail;
    
    if(head == NULL || head->next == NULL)
        return head;
    
    lesser = less_tail = create(0);
    greater = great_tail = create(0);
    
    
    for(curr = head; curr != NULL; curr = curr->next) {
        if(curr->val < x)
            less_tail = append(less_tail, curr->val);
        else
            great_tail = append(great_tail, curr->val);
    }
    
    struct ListNode* tmp;

    tmp = lesser;
    lesser = lesser->next;
    free(tmp);
    
    tmp = greater;
    greater = greater->next;
    free(tmp);
    
    if(lesser != NULL)
        less_tail->next = greater;
    else
        lesser = greater;
    
    return lesser;
}

struct ListNode* append(struct ListNode* to, int val) {
    to->next = create(val);
    return to->next;
}

struct ListNode* create(int val) {
    struct ListNode* tmp = malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    
    return tmp;
}
