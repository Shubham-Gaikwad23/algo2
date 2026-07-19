/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    // Left running product
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        ans[i] = nums[i - 1] * ans[i - 1];
    }

    // Right running product
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] = ans[i] * right;
        right *= nums[i];
    }
    return ans;
}
