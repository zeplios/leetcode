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
struct TreeNode** generate(int start, int end, int *retSize, int *num) {
    struct TreeNode** res = malloc(sizeof(struct TreeNode*) * num[end-start+1]);
    (*retSize) = 0;
    if (start > end) {
        res[(*retSize)++] = NULL;
        return res;
    }
    int i, j, k;
    for (i = start ; i <= end ; i++) {
        int lsize, rsize;
        struct TreeNode** lres = generate(start, i-1, &lsize, num);
        struct TreeNode** rres = generate(i+1, end, &rsize, num);
        for (j = 0 ; j < lsize ; j++) {
            for (k = 0 ; k < rsize ; k++) {
                struct TreeNode* tn = malloc(sizeof(struct TreeNode));
                tn->val = i;
                tn->left = lres[j];
                tn->right = rres[k];
                res[(*retSize)++] = tn;
            }
        }
    }
    return res;
}
struct TreeNode** generateTrees(int n, int* returnSize) {
    int* num = malloc(sizeof(int)*(n+2));
    num[0] = num[1] = 1;
    int i, j;
    for (i = 2 ; i <= n ; i++) {
        int sum = 0;
        for (j = 1 ; j <= i ; j++) {
            sum += num[j-1] * num[i-j];
        }
        num[i] = sum;
    }
    return generate(1, n, returnSize, num);
}