/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* !!! I think the code is right, but leetcode throws a compile error even I just declear(malloc) the result and return it */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    int *tree = malloc(sizeof(int)*numCourses);
    int *outTree = malloc(sizeof(int)*numCourses);
    int treeSize = 0, outTreeSize = 0, i, j;
    bool inTree[numCourses];
    for (i = 0 ; i < numCourses ; i++) {
        inTree[i] = false;
    }
    
    for (i = 0 ; i < numCourses ; i++) {
        for (j = 0 ; j < prerequisitesRowSize ; j++) {
            if (prerequisites[j][0] == i) {
                break;
            }
        }
        if (j == prerequisitesRowSize) {
            inTree[i] = true;
            tree[treeSize++] = i;
        } else {
            outTree[outTreeSize++] = i;
        }
    }
    int preTreeSize = 0;
    while (treeSize != numCourses && preTreeSize != treeSize) {
        preTreeSize = treeSize;
        for (i = 0 ; i < outTreeSize ; i++) {
            int cur = outTree[i];
            for (j = 0 ; j < prerequisitesRowSize ; j++) {
                if (prerequisites[j][0] == cur) {
                    int pre = prerequisites[j][1];
                    if (!inTree[pre]) {
                        break;
                    }
                }
            }
            if (j == prerequisitesRowSize) {
                inTree[cur] = true;
                tree[treeSize++] = cur;
                outTree[i] = outTree[--outTreeSize];
                i--;
            }
        }
    }
    if (treeSize == numCourses) {
        (* returnSize) = numCourses;
    } else {
        (* returnSize) = 0;
    }
    return tree;
}