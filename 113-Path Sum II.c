/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    (* returnSize) = 0;
    (* columnSizes) = malloc(10000 * sizeof(int*));
    int ** res = malloc(10000 * sizeof(int*));
    
    struct TreeNode* stack[10000];
    int top = 0, cursum = 0, i;
    struct TreeNode* cur = root;
    struct TreeNode* prePop = NULL;
    stack[top++] = NULL;
    while (cur != NULL) {
        while (cur) {
            stack[top++] = cur;
            cursum += cur->val;
            cur = cur->left;
        }
        while (true) {
            if ((cur = stack[top - 1]) == NULL) {
                // the first item in stack is NULL, cur == null means stack empty
                break;
            }
            if (cur->left == NULL && cur->right == NULL) {
                if (cursum == sum) {
                    res[(* returnSize)] = malloc((top-1) * sizeof(int));
                    (* columnSizes)[(* returnSize)] = top - 1;
                    for (i = 1 ; i < top ; i++) {
                        res[(* returnSize)][i-1] = stack[i]->val;
                    }
                    (* returnSize)++;
                }
            }
            if (cur->right != NULL && prePop != cur->right) {
                cur = cur->right;
                break;
            } else {
                prePop = cur;
                top--;
                cursum -= cur->val;
            }
        }
    }
    return res;
}