/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p == q) return p;
    
    struct TreeNode* cur = root;
    
    while (true) {
        if (p == cur || q == cur) return cur;
        if (p->val < cur->val && q->val < cur->val) {
            cur = cur->left;
        } else if (p->val >= cur->val && q->val >= cur->val) {
            cur = cur->right;
        } else {
            return cur;
        }
    }
    return NULL;
}