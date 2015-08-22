/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a, int b) {return a > b ? a : b;}
void swap(struct Interval* intervals, int i, int j) {
    int start = intervals[i].start;
    int end = intervals[i].end;
    intervals[i].start = intervals[j].start;
    intervals[i].end = intervals[j].end;
    intervals[j].start = start;
    intervals[j].end = end;
}
void quickSort(struct Interval* intervals, int start, int end) {
    if (start >= end) return;
    int i = start - 1, j;
    for (j = start ; j < end ; j++) {
        if (intervals[j].start <= intervals[end].start) {
            i++;
            swap(intervals, i, j);
        }
    }
    i++;
    swap(intervals, i, end);
    quickSort(intervals, start, i-1);
    quickSort(intervals, i+1, end);
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize <= 1) {
        (* returnSize) = intervalsSize;
        return intervals;
    }
    quickSort(intervals, 0, intervalsSize-1);
    (* returnSize) = 0;
    int i;
    for (i = 1 ; i < intervalsSize ; i++) {
        if (intervals[i].start > intervals[(* returnSize)].end) {
            (* returnSize)++;
            intervals[(* returnSize)].start = intervals[i].start;
            intervals[(* returnSize)].end = intervals[i].end;
        } else {
            intervals[(* returnSize)].end = max(intervals[(* returnSize)].end, intervals[i].end);
        }
    }
    (* returnSize)++;
    return intervals;
}