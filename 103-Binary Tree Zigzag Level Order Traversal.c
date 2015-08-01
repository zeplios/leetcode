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
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int** res = malloc(sizeof(int*) * 10000);
    (* columnSizes) = malloc(sizeof(int) * 10000);
    (* returnSize) = 0;
    
    int stackl2r[1000], stackr2l[1000];
    int l2rTop=0, r2lTop=0, pos=0;
    
    if (!root)
        return res;
    
    stackr2l[r2lTop++] = root;
    struct TreeNode* cur;
    while (r2lTop > 0) {
        (* columnSizes)[(* returnSize)] = r2lTop;
        res[(* returnSize)] = malloc(sizeof(int) * r2lTop);
        pos = 0;
        while (r2lTop > 0) {
            cur = stackr2l[--r2lTop];
            res[(* returnSize)][pos++] = cur->val;
            if (cur->left) stackl2r[l2rTop++] = cur->left;
            if (cur->right) stackl2r[l2rTop++] = cur->right;
        }
        (* returnSize)++;
        
        if (l2rTop == 0) {
            break;
        }
        
        (* columnSizes)[(* returnSize)] = l2rTop;
        res[(* returnSize)] = malloc(sizeof(int) * l2rTop);
        pos = 0;
        while (l2rTop > 0) {
            cur = stackl2r[--l2rTop];
            res[(* returnSize)][pos++] = cur->val;
            if (cur->right) stackr2l[r2lTop++] = cur->right;
            if (cur->left) stackr2l[r2lTop++] = cur->left;
        }
        (* returnSize)++;
    }
    return res;
}