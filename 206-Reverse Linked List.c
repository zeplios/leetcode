/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode * needtopoint = head;
    struct ListNode * needtomove = head->next;
    struct ListNode * next = needtomove->next;
    head->next = NULL;
    while (needtomove != NULL) {
        needtomove->next = needtopoint;
        needtopoint = needtomove;
        needtomove = next;
        if (needtomove != NULL) {
            next = needtomove->next;
        }
    }
    return needtopoint;
}