/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct ListNode * cur1 = l1;
    struct ListNode * cur2 = l2;
    struct ListNode * cur;
    struct ListNode * start;
    if (cur1->val < cur2->val) {
        start = cur = cur1;
        cur1 = cur1->next;
    } else {
        start = cur = cur2;
        cur2 = cur2->next;
    }
    while (1) {
        if (cur1 == NULL && cur2 == NULL) break;
        if (cur1 != NULL && cur2 == NULL) {
            cur->next = cur1;
            cur1 = cur1->next;
        } else if (cur1 == NULL && cur2 != NULL) {
            cur->next = cur2;
            cur2 = cur2->next;
        } else {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
        }
        cur = cur->next;
    }
    return start;
}