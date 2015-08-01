/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    struct TreeNode* stack[200];
    int sSize = 0, top = 0, cursum = 0;
    struct TreeNode* cur = root;
    while (cur != NULL) {
        stack[top++] = cur;
        stack[top++] = cur;
        sSize++;
        cursum += cur->val;
        if (cur->left != NULL) {
            cur = cur->left;
            continue;
        } else {
            while (top > 0) {
                cur = stack[--top];
                if (top > 0 && cur == stack[top-1]) {
                    // needs to go right
                    if (cur->left == NULL && cur->right == NULL) {
                        if (cursum == sum) {
                            return true;
                        }
                    } else if (cur->right != NULL) {
                        cur = cur->right;
                        break;
                    }
                } else {
                    sSize--;
                    cursum -= cur->val;
                }
            }
            if (top == 0) {
                cur = NULL;
            }
        }
    }
    return false;
}


/*===================================
更好的方法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    struct TreeNode* stack[200];
    int top = 0, cursum = 0;
    struct TreeNode* cur = root;
    struct TreeNode* prePop = NULL;
    stack[top++] = NULL;
    while (cur != NULL) {
        stack[top++] = cur;
        cursum += cur->val;
        if (cur->left != NULL) {
            cur = cur->left;
        } else {
            while (true) {
                if ((cur = stack[top - 1]) == NULL) {
                    // the first item in stack is NULL, cur == null means stack empty
                    break;
                }
                if (cur->left == NULL && cur->right == NULL) {
                    if (cursum == sum) {
                        return true;
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
    }
    return false;
}
=========================================*/