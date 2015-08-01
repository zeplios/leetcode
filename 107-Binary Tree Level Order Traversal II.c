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
int height(struct TreeNode* n) {
    if (n == NULL) return 0;
    int left = n->left ? height(n->left) : 0;
    int right = n->right ? height(n->right) : 0;
    return left > right ? left + 1 : right + 1;
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int QUEUE_MAX = 10000;
    (* returnSize) = height(root);
    (* columnSizes) = malloc((* returnSize) * sizeof(int));
    int ** res = malloc((* returnSize) * sizeof(int*));
    if (!root) return res;
    
    struct TreeNode* queue[QUEUE_MAX];
    int first = 0, last = 0, length = 0, arrayEnd = (* returnSize) - 1;
    if (root) {
        queue[first++] = root;
        queue[first++] = NULL;
    }
    
    int size = 1;
    res[arrayEnd] = malloc(size*sizeof(int));
    while (first != last) {
        struct TreeNode* n = queue[last++];
        last = (last >= QUEUE_MAX) ? 0 : last;
        
        if (n == NULL) {
            (* columnSizes)[arrayEnd] = length;
            arrayEnd--;
            size = 2 * length;
            if (arrayEnd < 0) {
                break;
            }
            res[arrayEnd] = malloc(size*sizeof(int));
            length = 0;
            if (last != first) {
                queue[first++] = NULL;
                first = (first >= QUEUE_MAX) ? 0 : first;
            }
            continue;
        }
        
        if (n->left != NULL) {
            queue[first++] = n->left;
            first = (first >= QUEUE_MAX) ? 0 : first;
        }
        if (n->right != NULL) {
            queue[first++] = n->right;
            first = (first >= QUEUE_MAX) ? 0 : first;
        }
        res[arrayEnd][length++] = n->val;
    }
    return res;
}