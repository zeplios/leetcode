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
#define MAX(a, b) a > b ? a : b
#define COMP(a) if ((a).start > ns[(* returnSize)].end) { \
                (* returnSize)++; \
                ns[(* returnSize)].start = (a).start; \
                ns[(* returnSize)].end = (a).end; \
            } else { \
                ns[(* returnSize)].end = MAX(ns[(* returnSize)].end, (a).end); \
            }
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* ns = malloc(sizeof(struct Interval) * (intervalsSize + 1));
    (* returnSize) = 0;
    int i;
    if (intervalsSize == 0 || intervals[0].start > newInterval.start) {
        i = 0;
        ns[(* returnSize)].start = newInterval.start;
        ns[(* returnSize)].end = newInterval.end;
        newInterval.start = newInterval.end = INT_MAX;
    } else if (intervalsSize > 0) {
        i = 1;
        ns[(* returnSize)].start = intervals[0].start;
        ns[(* returnSize)].end = intervals[0].end;
    }
    if (intervalsSize == 0) {
        (* returnSize)++;
        return ns;
    }
    for ( ; i < intervalsSize ; i++) {
        if (newInterval.start < intervals[i].start) {
            COMP(newInterval);
            newInterval.start = newInterval.end = INT_MAX;
            i--;
        } else {
            COMP(intervals[i]);
        }
    }
    if (newInterval.start != INT_MAX) {
        COMP(newInterval);
    }
    (* returnSize)++;
    return ns;
}