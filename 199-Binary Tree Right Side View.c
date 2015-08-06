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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int * res = malloc(1000*sizeof(int));
    (* returnSize) = 0;
    
    int QUEUE_MAX = 10000;
    struct TreeLinkNode* queue[QUEUE_MAX];
    struct TreeLinkNode* preNode = NULL, *n;
    int first = 0, last = 0;
    if (root) {
        queue[first++] = root;
        queue[first++] = NULL;
    } else {
        return res;
    }
    
    while (first != last) {
        preNode = n;
        n = queue[last++];
        last = (last >= QUEUE_MAX) ? 0 : last;
        
        if (n == NULL) {
            if (last != first) {
                queue[first++] = NULL;
                first = (first >= QUEUE_MAX) ? 0 : first;
            }
            res[(* returnSize)++] = preNode->val;
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
    }
    return res;
}