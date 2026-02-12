/*
Problem No   : 55
Problem Name : Jump Game
Link         : https://leetcode.com/problems/jump-game/
Description  : Given an integer array where each element represents the maximum 
               jump length at that position, determine whether you can reach 
               the last index starting from the first index.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        if(n == 1) {
            return true;
        }
        
        for(int i = 0; i < n; i++) {
            if(i > max_reach) {
                return false;
            }
            
            max_reach = max(max_reach, i + nums[i]);
            
            if(max_reach > n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
