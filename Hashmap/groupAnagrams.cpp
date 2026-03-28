#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Group Anagrams
 * 
 * Approach:
 * - Sort each word to create a key
 * - Use unordered_map to group original strings by this key
 * - Return all grouped values
 * 
 * Time Complexity: O(n * k log k)
 * Space Complexity: O(n * k)
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> words;

        // Step 1: Create groups using sorted key
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            words[word].push_back(strs[i]);
        }

        // Step 2: Collect results
        for (auto& it : words) {
            res.push_back(it.second);
        }

        return res;
    }
};