/*
    Problem: Remove Duplicates from Sorted Array
    LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    Difficulty: Easy
    Topic: Array, Two Pointers / In-place
*/
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = numsSize;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (nums[i] == nums[j]) {
                for (int z = j; z < k - 1; z++) {
                    nums[z] = nums[z + 1];
                }
                k--;
                j--;
            }
        }
    }
    return k;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = removeDuplicates(nums, n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\nNumber of unique elements: %d\n", k);

    return 0;
}