/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* i = NULL;
    struct ListNode* j = head;
    struct ListNode* prej;
    struct ListNode* tmp;
    while (j) {
        if (j->val >= x) {
            prej = j;
            j = j->next;
        } else {
            if (i == NULL && j == head) {
                // hasn't met the node greater than or equal to x
                i = head;
                j = j->next;
            } else if (i == NULL) {
                // has met the node greater than or equal to x
                i = j;
                j = j->next;
                prej->next = j;
                i->next = head;
                head = i;
            } else if (i->next == j) {
                // hasn't met the node greater than or equal to x
                i = j;
                j = j->next;
            } else {
                // hasn met the node greater than or equal to x
                tmp = j;
                j = j->next;
                prej->next = j;
                tmp->next = i->next;
                i->next = tmp;
                i = i->next;
            }
        }
    }
    return head;
}