/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    // assert node->next != NULL
    struct ListNode* ne = node->next;
    node->val = ne->val;
    node->next = ne->next;
    free(ne);
}