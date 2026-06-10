// LeetCode 881: Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0;
        int j = people.size() - 1;

        sort(people.begin(), people.end());

        int boats = 0;

        while (i <= j) {
            int sum = people[i] + people[j];

            if (sum <= limit) {
                i++;
                j--;
            } else {
                j--;
            }

            boats++;
        }

        return boats;
    }
};