/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode* cur = root;
    struct TreeNode* tmp;
    while (cur != NULL) {
        if (cur->left != NULL) {
            tmp = cur->left;
            while (tmp->right != NULL) {
                tmp = tmp->right;
            }
            tmp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
            cur = cur->right;
            continue;
        } else {
            cur = cur->right;
        }
    }
    
}