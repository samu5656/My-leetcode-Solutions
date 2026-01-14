/*
    Problem: Search Insert Position
    LeetCode: https://leetcode.com/problems/search-insert-position/
    Difficulty: Easy
    Topic: Array, Linear Search
*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return numsSize;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int size = sizeof(nums) / sizeof(nums[0]);

    int index = searchInsert(nums, size, target);
    printf("Insert position: %d\n", index);

    return 0;
}
