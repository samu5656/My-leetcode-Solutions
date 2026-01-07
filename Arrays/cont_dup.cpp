/*
    Problem: Contains Duplicate
    LeetCode: https://leetcode.com/problems/contains-duplicate/
    Difficulty: Easy
    Topic: Array, Hashing
    Approach: Unordered Set (Hashing)

    Time Complexity: O(n) average
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> checked;

        for (int x : nums) {
            if (checked.find(x) != checked.end()) {
                return true;
            }
            checked.insert(x);
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    if (sol.containsDuplicate(nums)) {
        cout << "Duplicate found" << endl;
    } else {
        cout << "No duplicate found" << endl;
    }

    return 0;
}
