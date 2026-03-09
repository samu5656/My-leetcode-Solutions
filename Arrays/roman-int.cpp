/*
Problem: Roman to Integer
Platform: LeetCode
Difficulty: Easy

Roman numerals are represented by seven symbols:
I, V, X, L, C, D, M.

Values:
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Rule:
If a smaller value appears before a larger value, subtract it.
Otherwise, add it.

Example:
Input: "MCMIV"
Output: 1904
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> value = {
            {'I',1}, {'V',5}, {'X',10},
            {'L',50}, {'C',100}, {'D',500}, {'M',1000}
        };

        int result = 0;

        for(int i = 0; i < s.length(); i++) {

            // If current value is smaller than next value → subtract
            if(i < s.length()-1 && value[s[i]] < value[s[i+1]]) {
                result -= value[s[i]];
            }
            else {
                result += value[s[i]];
            }
        }

        return result;
    }
};

int main() {

    Solution sol;
    string roman = "MCMIV";

    cout << "Roman: " << roman << endl;
    cout << "Integer: " << sol.romanToInt(roman) << endl;

    return 0;
}