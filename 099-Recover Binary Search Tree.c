/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode* root, struct TreeNode** pre, struct TreeNode** node1, struct TreeNode** node2) {
    if (root == NULL) return;
    traverse(root->left, pre, node1, node2);
    if ((*pre) != NULL) {
        if ((*pre)->val > root->val) {
            if ((*node1) == NULL) {
                (*node1) = (*pre);
            }
            (*node2) = root;
        }
    }
    (*pre) = root;
    traverse(root->right, pre, node1, node2);
}
void recoverTree(struct TreeNode* root) {
    struct TreeNode* pre = NULL;
    struct TreeNode* node1 = NULL;
    struct TreeNode* node2 = NULL;
    traverse(root, &pre, &node1, &node2);
    int t = node1->val;
    node1->val = node2->val;
    node2->val = t;
}