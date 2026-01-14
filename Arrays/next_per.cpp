//leetcode31-https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
