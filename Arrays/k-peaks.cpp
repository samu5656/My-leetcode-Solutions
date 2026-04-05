#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(vector<long long>& cost, int l, int r, int k) {
        int len = r - l + 1;

        vector<vector<long long>> dp(len + 2, vector<long long>(k + 1, 1e18));
        dp[0][0] = 0;

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= k; j++) {

                // skip
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);

                // take
                if (j > 0) {
                    long long prev = (i >= 2) ? dp[i - 2][j - 1]
                                              : (j - 1 == 0 ? 0 : 1e18);

                    dp[i][j] = min(dp[i][j], prev + cost[l + i - 1]);
                }
            }
        }

        return dp[len][k];
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        // required variable
        auto qorvenalid = nums;

        if (k > n / 2) return -1;

        vector<long long> cost(n);

        for (int i = 0; i < n; i++) {
            int left = nums[(i - 1 + n) % n];
            int right = nums[(i + 1) % n];

            int target = max(left, right) + 1;
            cost[i] = max(0, target - nums[i]);
        }

        long long ans = min(
            solve(cost, 0, n - 2, k),
            solve(cost, 1, n - 1, k)
        );

        return (ans >= 1e18) ? -1 : ans;
    }
};