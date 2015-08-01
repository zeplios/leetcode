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
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    (* returnSize) = 0;
    (* columnSizes) = malloc(10000 * sizeof(int));
    int ** res = malloc(10000 * sizeof(int*));
    if (!root) return res;
    
    int QUEUE_MAX = 10000;
    struct TreeNode* queue[QUEUE_MAX];
    int first = 0, last = 0, length = 0;
    if (root) {
        queue[first++] = root;
        queue[first++] = NULL;
    }
    
    int size = 1;
    res[(* returnSize)] = malloc(size*sizeof(int));
    while (first != last) {
        struct TreeNode* n = queue[last++];
        last = (last >= QUEUE_MAX) ? 0 : last;
        
        if (n == NULL) {
            (* columnSizes)[(* returnSize)++] = length;
            size = 2 * length;
            res[(* returnSize)] = malloc(size*sizeof(int));
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
        res[(* returnSize)][length++] = n->val;
    }
    return res;
}