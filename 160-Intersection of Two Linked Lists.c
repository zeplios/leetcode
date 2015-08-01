/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int size1 = 0, size2 = 0, i;
    struct ListNode * node = headA;
    while (node != NULL) {size1++; node = node->next; }
    node = headB;
    while (node != NULL) {size2++; node = node->next; }
    struct ListNode * cursorA = headA;
    struct ListNode * cursorB = headB;
    if (size1 > size2) {
        for (i = 0 ; i < size1 - size2 ; i++) {
            cursorA = cursorA->next;
        }
    }
    if (size2 > size1) {
        for (i = 0 ; i < size2 - size1 ; i++) {
            cursorB = cursorB->next;
        }
    }
    while (cursorB != NULL) {
        if (cursorA == cursorB) {
            return cursorA;
        }
        cursorA = cursorA->next;
        cursorB = cursorB->next;
    }
    return NULL;
}