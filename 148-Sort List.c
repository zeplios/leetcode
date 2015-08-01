/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int* num, int i, int j) {
    int t = num[i];
    num[i] = num[j];
    num[j] = t;
}
void createHeap(int* num, int size) {
    int i;
    for (i = size/2-1 ; i >= 0 ; i--) {
        heapSort(num, i, size);
    }
}
int heapSort(int* num, int start, int size) {
    int i = start;
    while (i <= size/2-1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (rightChild < size && num[rightChild] < num[leftChild] 
                && num[rightChild] < num[i]) {
            swap(num, i, 2*i+2);
            i = 2*i+2;
            continue;
        }
        if (num[i] > num[leftChild]) {
            swap(num, i, 2*i+1);
            i = 2*i+1;
            continue;
        }
        break;
    }
    return num[0];
}
struct ListNode* sortList(struct ListNode* head) {
    int c = 0;
    struct ListNode* cur = head;
    while (cur) {
        c++;
        cur = cur->next;
    }
    
    int num[c];
    cur = head;
    c = 0;
    while (cur) {
        num[c++] = cur->val;
        cur = cur->next;
    }
    createHeap(num, c);
    
    cur = head;
    while (cur) {
        cur->val = heapSort(num, 0, c);
        num[0] = num[--c];
        cur = cur->next;
    }
    return head;
}