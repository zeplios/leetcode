/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode * slowNode = head;
    struct ListNode * fastNode = head;
    while (fastNode != NULL) {
        slowNode = slowNode->next;
        fastNode = fastNode->next != NULL ? fastNode->next->next : NULL;
        if (fastNode == NULL) {
            return NULL;
        }
        if (slowNode == fastNode) {
            break;
        }
    }
    fastNode = head;
    while (slowNode != fastNode) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    return fastNode;
}