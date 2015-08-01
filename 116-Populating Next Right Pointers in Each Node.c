/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (root == NULL) return;
    root->next = NULL;
    struct TreeLinkNode * cur = root;
    struct TreeLinkNode * left = root->left;
    struct TreeLinkNode * right = root->right;
    connect(left);
    connect(right);
    while (left != NULL) {
        left->next = right;
        left = left->right;
        right = right->left;
    }
}