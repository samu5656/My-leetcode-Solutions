// LeetCode 904 - Fruit Into Baskets: https://leetcode.com/problems/fruit-into-baskets/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        unordered_map<int, int> freq;
        int maxlen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
