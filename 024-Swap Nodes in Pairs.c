/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* start = head->next;
    struct ListNode* cur = head;
    struct ListNode* first = start->next;
    struct ListNode* second = NULL;
    if (first != NULL && first->next != NULL) {
        second = first->next->next;
    }
    head->next->next = head;
    head->next = NULL;
    while(first != NULL) {
        if (first->next != NULL) {
            cur->next = first->next;
            first->next->next = first;
        } else {
            cur->next = first;
        }
        
        cur = first;
        cur->next = NULL;
        first = second;
        if (second != NULL && second->next != NULL) {
            second = second->next->next;
        } else {
            second = NULL;
        }
    }
    return start;
}