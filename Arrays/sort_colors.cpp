#include <iostream>
#include <vector>
using namespace std;

// Intuition
// The array contains only 0s, 1s, and 2s. A simple way to sort the array
// is to repeatedly compare adjacent elements and swap them if needed,
// similar to the Bubble Sort algorithm.

// Approach
// Use Bubble Sort to arrange elements in ascending order.
// - The outer loop controls the number of passes.
// - The inner loop compares adjacent elements and swaps them if out of order.
// After each pass, the largest element moves to the end.

// Complexity
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    cout << "Sorted array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
