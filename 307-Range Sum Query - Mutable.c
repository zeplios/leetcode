typedef struct SegmentTreeNode {
    int start, end, sum;
    struct SegmentTreeNode *left, *right;
} SegTreeNode;

SegTreeNode* initTree(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    SegTreeNode* node = malloc(sizeof(SegTreeNode));
    node->start = start;
    node->end = end;
    if (start == end) {
        node->sum = nums[start];
    } else {
        int mid = start  + (end - start) / 2;             
        node->left = initTree(nums, start, mid);
        node->right = initTree(nums, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
    }         
    return node;
}

void updateTree(SegTreeNode* root, int i, int val) {
    if (root->start == root->end) {
        root->sum = val;
    } else {
        int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) {
            updateTree(root->left, i, val);
        } else {
            updateTree(root->right, i, val);
        }
        root->sum = root->left->sum + root->right->sum;
    }
}

int sumTree(SegTreeNode* root, int start, int end) {
    if (root->start == start && root->end == end) {
        return root->sum;
    } else {
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return sumTree(root->left, start, end);
        } else if (start > mid) {
            return sumTree(root->right, start, end);
        }  else {    
            return sumTree(root->left, start, mid) + sumTree(root->right, mid+1, end);
        }
    }
}

struct NumArray {
    SegTreeNode* root;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* numArr = malloc(sizeof(struct NumArray));
    numArr->root = initTree(nums, 0, numsSize-1);
    return numArr;
}

void update(struct NumArray* numArray, int i, int val) {
    updateTree(numArray->root, i, val);
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return sumTree(numArray->root, i, j);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    //free(numArray->nums);
    //free(numArray->sums);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// update(numArray, 1, 10);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
