/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int * res = malloc(1000 * sizeof(int));
    struct TreeNode** stack = malloc(100 * sizeof(struct TreeNode*));
    int top = 0, count = 0;
    struct TreeNode* cur = root;
    
    while (top > 0 || cur != NULL) {
        while (cur != NULL) {
            stack[top++] = cur;
            cur = cur->left;
        }
        
        cur = stack[--top];
        res[count++] = cur->val;
        if (cur->right != NULL) {
            cur = cur->right;
        } else {
            cur = NULL;
        }
    }
    (*returnSize) = count;
    return res;
}
