/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    int num[10000];
    int top = 0, max = INT_MIN;
    
    struct TreeNode* cur = root;
    struct TreeNode* prePop = NULL;
    while (cur || top > 0) {
        while (cur) {
            num[top] = 0;
            stack[top++] = cur;
            cur = cur->left;
        }
        
        cur = stack[top-1];
        if (cur->right != NULL && cur->right != prePop) {
            cur = cur->right;
        } else {
            max = cur->val > max ? cur->val : max;
            if (top > 1 && cur == stack[top-2]->right) {
                int rightmax = num[top-1] + cur->val;
                rightmax = rightmax > 0 ? rightmax : 0;
                int curmax = num[top-2] + stack[top-2]->val + rightmax;
                num[top-2] = num[top-2] > rightmax ? num[top-2] : rightmax;
                max = curmax > max ? curmax : max;
            } else if (top > 1) {
                num[top-2] = num[top-1] + stack[top-1]->val;
                num[top-2] = num[top-2] > 0 ? num[top-2] : 0;
                int curmax = num[top-2] + stack[top-2]->val;
                max = curmax > max ? curmax : max;
            }
            prePop = cur;
            top--;
            cur = NULL;
        }
    }
    return max;
}