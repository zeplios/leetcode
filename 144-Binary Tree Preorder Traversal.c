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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int * res = malloc(1000 * sizeof(int));
    struct TreeNode** stack = malloc(100 * sizeof(struct TreeNode*));
    int top = 0, count = 0;
    struct TreeNode* cur = root;
    
    while (top > 0 || cur != NULL) {
        while (cur != NULL) {
            res[count++] = cur->val;
            stack[top++] = cur;
            cur = cur->left;
        }
        
        cur = stack[--top];
        if (cur->right != NULL) {
            cur = cur->right;
        } else {
            cur = NULL;
        }
    }
    (*returnSize) = count;
    return res;
}
