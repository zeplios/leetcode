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
    struct TreeNode** stack = malloc(100 * sizeof(struct TreeNode*));
    int * res = malloc(1000 * sizeof(int));
    int stackTop = 0;
    (*returnSize) = 0;
    struct TreeNode* cur = root;
    while (cur != NULL) {
        res[(*returnSize)++] = cur->val;
        stack[stackTop++] = cur;
        if (cur->left != NULL) {
            cur = cur->left;
        } else {
            while (true) {
                if (stackTop == 0) {
            		cur = NULL;
            		break;
				}
                cur = stack[--stackTop];
                if (cur->right != NULL) {
                    cur = cur->right;
                    break;
                }
            }
        }
    }
    return res;
}