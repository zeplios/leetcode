/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArray(int* nums, int start, int end) {
    if (end < start) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    int cur = (start+end) / 2;
    root->val = nums[cur];
    root->left = sortedArray(nums, start, cur-1);
    root->right = sortedArray(nums, cur+1, end);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArray(nums, 0, numsSize-1);
}