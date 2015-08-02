/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int add(struct ListNode* l1, struct ListNode* l2, int* carry) {
    int val = ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + *carry;
    if (val > 9) {
        *carry = 1;
        val -= 10;
    } else {
        *carry = 0;
    }
    return val;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* cur = malloc(sizeof(struct ListNode));
    struct ListNode* head = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = add(l1, l2, &carry);
        if (head == NULL) {
            cur = tmp;
            head = tmp;
        } else {
            cur->next = tmp;
            cur = tmp;
        }
        l1 = (l1 != NULL) ? l1->next : NULL;
        l2 = (l2 != NULL) ? l2->next : NULL;
    }
    return head;
}