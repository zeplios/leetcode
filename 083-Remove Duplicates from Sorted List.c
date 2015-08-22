/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->val == cur->next->val) {
            struct ListNode* del = cur->next;
            cur->next = cur->next->next;
            free(del);
            continue;
        }
        cur = cur->next;
    }
    return head;
}