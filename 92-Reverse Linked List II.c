/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    n = n - m + 1; // convert n from end index to length
    while (--m) {
        pre = cur;
        cur = cur->next;
    }
    // pre is the last element of part1;
    // cur is the last element of part2;
    
    if (cur == NULL || cur->next == NULL) return head;
    struct ListNode * needtopoint = cur;
    struct ListNode * needtomove = needtopoint->next;
    struct ListNode * next = needtomove->next;
    
    while (needtomove != NULL && --n) {
        needtomove->next = needtopoint;
        needtopoint = needtomove;
        needtomove = next;
        if (needtomove != NULL) {
            next = needtomove->next;
        }
    }
    cur->next = needtomove;
    if (pre != NULL) {
        pre->next = needtopoint;
        return head;
    } else {
        return needtopoint;
    }
}