/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int count = 0;
    struct ListNode* cur = head;
    struct ListNode* lastend = NULL, * tmp = NULL;
    while (cur && ++count) cur = cur->next;
    
    count = count - count % k;
    
    cur = head;
    int t = k;
    while (count--) {
        if (t-- > 1) {
            // only need to reverse k-1 times
            tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = (lastend == NULL) ? head : lastend->next;
            head = (lastend == NULL) ? tmp : head;
            if (lastend != NULL) lastend->next = tmp;
        } else {
            lastend = cur;
            cur = cur->next;
            t = k;
        }
    }
    return head;
}