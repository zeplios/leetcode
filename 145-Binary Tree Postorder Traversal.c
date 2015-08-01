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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode** stack = malloc(100 * sizeof(struct TreeNode*));
    int* stack4LeftOver = malloc(100 * sizeof(int));
    int * res = malloc(1000 * sizeof(int));
    int stackTop = 0;
    (*returnSize) = 0;
    struct TreeNode* cur = root;
    while (cur != NULL) {
        stack[stackTop] = cur;
        stack4LeftOver[stackTop++] = 0;
        if (cur->left != NULL) {
            cur = cur->left;
        } else {
            while (true) {
                if (stackTop == 0) {
            		cur = NULL;
            		break;
				}
                if (stack4LeftOver[stackTop-1]) {
                    res[(*returnSize)++] = stack[--stackTop]->val;
                } else {
                    cur = stack[stackTop-1];
                    stack4LeftOver[stackTop-1] = 1;
                    if (cur->right != NULL) {
                        cur = cur->right;
                        break;
                    }
                }
            }
        }
    }
    return res;
}