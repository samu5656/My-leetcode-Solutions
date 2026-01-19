#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = s.removeElement(nums, val);

    cout << "k = " << k << endl;
    cout << "Modified array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}

