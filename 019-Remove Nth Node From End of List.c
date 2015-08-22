/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (n == 0) {
        return head;
    }
    struct ListNode* f = head;
    struct ListNode* l = head;
    while (n--) {
        if (f != NULL) {
            f = f->next;
        } else {
            // n > the length of list
            return head;
        }
    }
    if (f == NULL) {
        // n == the length of list
        return head == NULL ? NULL : head->next;
    }
    while (f->next != NULL) {
        f = f->next;
        l = l->next;
    }
    l->next = l->next->next;
    return head;
}