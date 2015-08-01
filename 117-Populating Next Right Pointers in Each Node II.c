/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    int QUEUE_MAX = 10000;
    struct TreeLinkNode* queue[QUEUE_MAX];
    struct TreeLinkNode* preNode = NULL;
    int first = 0, last = 0;
    if (root) {
        queue[first++] = root;
        queue[first++] = NULL;
    }
    
    while (first != last) {
        struct TreeLinkNode* n = queue[last++];
        last = (last >= QUEUE_MAX) ? 0 : last;
        
        if (preNode != NULL) {
            preNode->next = n;
        }
        preNode = n;
        
        if (n == NULL) {
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
    }
}