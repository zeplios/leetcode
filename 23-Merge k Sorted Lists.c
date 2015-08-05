/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* heapSort(struct ListNode** nums, int numsSize, int top) {
    int i = top;
    while (i < numsSize / 2) {
        if (2*i+2 < numsSize && nums[2*i+1]->val > nums[2*i+2]->val) {
            if (nums[i]->val > nums[2*i+2]->val) {
                struct ListNode* t = nums[i];
                nums[i] = nums[2*i+2];
                nums[2*i+2] = t;
                i = 2 * i + 2;
            } else {
                break;
            }
        } else {
            if (nums[i]->val > nums[2*i+1]->val) {
                struct ListNode* t = nums[i];
                nums[i] = nums[2*i+1];
                nums[2*i+1] = t;
                i = 2 * i + 1;
            } else {
                break;
            }
        }
    }
    return nums[0];
}
void createHeap(struct ListNode** nums, int numsSize) {
    int i;
    for (i = numsSize / 2 - 1 ; i >= 0 ; i--) {
        heapSort(nums, numsSize, i);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* heap[listsSize];
    int i, count = 0;
    for (i = 0 ; i < listsSize ; i++) {
        if (lists[i] != NULL) {
            heap[count++] = lists[i];
        }
    }
    if (count == 0) return NULL;
    createHeap(heap, count);
    
    struct ListNode* res = heap[0];
    struct ListNode* cur = res;
    while (cur != NULL) {
        if (cur->next != NULL || count == 1) {
            heap[0] = cur->next;
        } else if (count > 1) {
            heap[0] = heap[--count];
        }
        heapSort(heap, count, 0);
        cur->next = heap[0]; // heap[0] may be null
        cur = cur->next;
    }
    return res;
}