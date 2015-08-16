/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* !!! I think the code is right, but leetcode throws a compile error even I just declear(malloc) the result and return it */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    int *level = malloc(sizeof(int) * numCourses);
    int *res = malloc(sizeof(int) * numCourses);
    int size = 0, i, j, rowNum = prerequisitesRowSize;
    for (i = 0 ; i < numCourses ; i++) {
        level[i] = -1;
    }
    
    int curLevel = 0, preSize = -1;
    while (size < numCourses && preSize != size) {
        preSize = size;
        for (i = 0 ; i < numCourses ; i++) {
            if (level[i] >= 0) continue;
            for (j = 0 ; j < rowNum ; j++) {
                int c0 = prerequisites[j][0];
                int c1 = prerequisites[j][1];
                if (c0 == i && (level[c1] == -1 || level[c1] == curLevel)) {
                    break;
                }
            }
            if (j == rowNum) {
                level[i] = curLevel;
                res[size++] = i;
            }
        }
        curLevel++;
    }
    if (size == numCourses) {
        (* returnSize) = numCourses;
    } else {
        (* returnSize) = 0;
    }
    return res;
}
