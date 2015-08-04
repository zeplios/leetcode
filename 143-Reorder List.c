/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return;
    
    struct ListNode* slow = head, * fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next != NULL) fast = fast->next;
    while (slow->next != fast) {
        struct ListNode* tmp = fast->next;
        fast->next = slow->next;
        slow->next = slow->next->next;
        fast->next->next = tmp;
    }
    while (head != slow) {
        struct ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        tmp->next = head->next;
        head->next = tmp;
        head = head->next->next;
    }
}