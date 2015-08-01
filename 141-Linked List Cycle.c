/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode * slowNode = head;
    struct ListNode * fastNode = head->next;
    if (slowNode == fastNode) return true;
    while (fastNode != NULL) {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
        if (fastNode == NULL) {
            break;
        }
        if (slowNode == fastNode) {
            return true;
        }
        fastNode = fastNode->next;
        if (slowNode == fastNode) {
            return true;
        }
    }
    return false;
}