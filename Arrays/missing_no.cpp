//Leetcode-268: Missing number
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        for(int i=0;i<=n;i++)
        {
            xr^=i;
        }
        for(int num : nums)
        {
            xr^=num;
        }
        return xr;
    }
};