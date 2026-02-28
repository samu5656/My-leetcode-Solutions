// LeetCode 134 - Gas Station
// Approach: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int g_sum = 0, c_sum = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            g_sum += gas[i];
            c_sum += cost[i];
        }

        if(g_sum < c_sum)
        {
            return -1;
        }

        int tank = 0, start = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            tank += gas[i] - cost[i];

            if(tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};