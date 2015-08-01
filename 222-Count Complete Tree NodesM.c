/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int all(int h) {
    int i, res = 1;
    for (i = 0 ; i < h ; i++) {
        res *= 2;
    }
    return res - 1;
}

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    
    struct TreeNode* cur = root;
    int lh = 0, rh = 0;
    while (cur) {
        lh++;
        cur = cur->left;
    }
    cur = root;
    while (cur) {
        rh++;
        cur = cur->right;
    }
    
    if (lh == rh) {
        return all(lh);
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}