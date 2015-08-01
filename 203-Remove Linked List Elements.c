/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;
    struct ListNode * cur = head;
    struct ListNode * start = head;
    while (cur->val == val) {
        cur = cur->next;
        start = cur;
        if (cur == NULL) {
            return NULL;
        }
    }
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            struct ListNode * d = cur->next;
            cur->next = cur->next->next;
            free(d);
        } else {
            cur = cur->next;
        }
    }
    return start;
}