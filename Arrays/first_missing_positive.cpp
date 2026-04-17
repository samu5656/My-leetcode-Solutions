#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: 41. First Missing Positive
 * Link: https://leetcode.com/problems/first-missing-positive/
 * * Approach: 
 * We use a "Cyclic Sort" or "Index Mapping" technique. Since the first missing 
 * positive must be in the range [1, n+1], we try to place every number 'x' 
 * at index 'x-1'. We then traverse the array to find the first index 'i' 
 * where nums[i] != i + 1.
 * * Time Complexity: O(n) - Each element is moved to its correct position at most once.
 * Space Complexity: O(1) - We modify the input array in-place.
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            // While the current number is in range [1, n] and is not at its correct position
            // AND the target position doesn't already have the correct number (prevents infinite loop)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Second pass: find the first index that doesn't match the expected value
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers 1 to n are present, the answer is n + 1
        return n + 1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 0};
    cout << "Input: [1, 2, 0] | Output: " << sol.firstMissingPositive(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {3, 4, -1, 1};
    cout << "Input: [3, 4, -1, 1] | Output: " << sol.firstMissingPositive(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {7, 8, 9, 11, 12};
    cout << "Input: [7, 8, 9, 11, 12] | Output: " << sol.firstMissingPositive(nums3) << endl;

    return 0;
}