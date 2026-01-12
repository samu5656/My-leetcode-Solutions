//leetcode-349-Intersection of two arrays
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (auto x : nums1) {
            for (auto y : nums2) {
                if (x == y) {
                    if (find(result.begin(), result.end(), x) == result.end()) {
                        result.push_back(x);
                    }
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
