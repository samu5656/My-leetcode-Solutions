#include <bits/stdc++.h>
using namespace std;

/*
    Jump Game II
    ------------
    Given an array nums where nums[i] represents the maximum jump length 
    from index i, return the minimum number of jumps to reach the last index.

    Greedy Approach:
    - far  = farthest reachable index while scanning current range
    - near = boundary of current jump range
    - jump = number of jumps taken

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int near = 0;   // end of current jump range
        int far  = 0;   // farthest reachable index
        int jump = 0;   // jump count

        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + nums[i]);

            // reached end of current range → take jump
            if (i == near) {
                jump++;
                near = far;
            }
        }
        return jump;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps: " << sol.jump(nums) << endl;
    return 0;
}