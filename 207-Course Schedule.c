bool canFind(int** prerequisites, int prerequisitesRowSize, int pos, bool *isfinding, bool *canfind) {
    if (canfind[pos]) {
        return true;
    }
    isfinding[pos] = true;
    int i;
    for (i = 0 ; i < prerequisitesRowSize ; i++) {
        if (prerequisites[i][0] == pos) {
            int pre = prerequisites[i][1];
            if (isfinding[pre]) {
                // loop appears
                return false;
            }
            canfind[pre] = canFind(prerequisites, prerequisitesRowSize, pre, isfinding, canfind);
            if (!canfind[pre]) {
                return false;
            }
        }
    }
    isfinding[pos] = false;
    return true;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    bool isfinding[numCourses], canfind[numCourses];
    memset(isfinding, false, sizeof(bool) * numCourses); // whether is finding
    memset(canfind, false, sizeof(bool) * numCourses);   // whether the sourse can be started
    int i;
    for (i = 0 ; i < numCourses ; i++) {
        if (!canFind(prerequisites, prerequisitesRowSize, i, isfinding, canfind)) {
            return false;
        }
    }
    return true;
}