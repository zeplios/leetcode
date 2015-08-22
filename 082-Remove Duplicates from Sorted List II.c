/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    while (head->val == head->next->val) {
        int value = head->val;
        while (head != NULL && head->val == value) {
            head = head->next;
        }
        if (head == NULL || head->next == NULL) return head;
    }
    struct ListNode* cur = head;
    while (cur->next->next != NULL) {
        while (cur->next->val == cur->next->next->val) {
            int value = cur->next->val;
            while (cur->next != NULL && cur->next->val == value) {
                cur->next = cur->next->next;
            }
            if (cur->next == NULL || cur->next->next == NULL) return head;
        }
        cur = cur->next;
    }
    return head;
}