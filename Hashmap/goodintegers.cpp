#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, vector<pair<int,int>>> mp;
        vector<int> result;

        int limit = cbrt(n);

        for (int a = 0; a < limit; a++) {
            for (int b = a; b < limit; b++) {
                int sum = a*a*a + b*b*b;
                if (sum > n) break;

                mp[sum].push_back({a, b});
            }
        }

        for (auto &[sum, pairs] : mp) {
            if (pairs.size() >= 2) {
                result.push_back(sum);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};