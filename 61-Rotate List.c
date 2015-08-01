/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int count = 0;
    struct ListNode* cur = head;
    while (cur && ++count) cur = cur->next;
    if (count < 2) return head;
    
    k = k % count;
    if (k == 0) return head;
    
    struct ListNode* fast = head;
    while (k--) fast = fast->next;
    
    cur = head;
    while (fast->next != NULL) {
        fast = fast->next;
        cur = cur->next;
    }
    
    fast->next = head;
    head = cur->next;
    cur->next = NULL;
    
    return head;
}