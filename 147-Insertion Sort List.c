/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* ret = head;
    struct ListNode* pre = head;
    struct ListNode* cur = head->next;
    struct ListNode* nxt;
    while (cur) {
        nxt = cur->next;
        if (cur->val >= pre->val) {
            pre = cur;
        } else if (cur->val <= ret->val) {
            pre->next = cur->next;
            cur->next = ret;
            ret = cur;
        } else {
            pre->next = cur->next;
            struct ListNode* tmp = ret;
            while (cur->val > tmp->next->val) tmp = tmp->next;
            cur->next = tmp->next;
            tmp->next = cur;
        }
        cur = nxt;
    }
    return ret;
}