// LeetCode: Shuffle the Array
// Problem: Given array nums = [x1,x2,...,xn,y1,y2,...,yn]
// Return [x1,y1,x2,y2,...,xn,yn]

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);

        for (int i = 0; i < n; i++) {
            res[2 * i] = nums[i];        // place x values
            res[2 * i + 1] = nums[n + i]; // place y values
        }

        return res;
    }
};