/* Number of Zero-Filled Subarrays 
Approach : Counting Consecutive Zeros
Time Complexity: O(n). We make a single pass through the array, doing O(1) work per element.
Space Complexity: O(1). We only use two variables (count and consecutiveZeros) regardless of input size.*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                count = 0;
            } else {
                count++;
                total+=count;
            }
        }
        return total;
    }
};