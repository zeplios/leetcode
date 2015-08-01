/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* getRoot(struct ListNode** head, int count) {
    if (count <= 0) {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->left = getRoot(head, count / 2);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = getRoot(head, count - count / 2 - 1);
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode* cur = head;
    int count = 0;
    while (cur) {
        count++;
        cur = cur->next;
    }
    if (count == 0) {
        return NULL;
    }
    return getRoot(&head, count);
}