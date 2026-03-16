// Minimum Size Subarray Sum
// Approach: Sliding Window (Two Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;              // Left pointer of window
        int sum = 0;               // Current window sum
        int min_count = INT_MAX;   // Store minimum length

        // Expand window using right pointer (i)
        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];        // Add current element to window

            // Shrink window while condition is satisfied
            while (sum >= target) {

                // Update minimum length
                min_count = min(min_count, i - left + 1);

                // Remove left element and move left pointer
                sum -= nums[left];
                left++;
            }
        }

        // If no valid subarray found return 0
        if (min_count != INT_MAX) {
            return min_count;
        } else {
            return 0;
        }
    }
};
