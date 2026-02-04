#include <vector>
#include <climits>
using namespace std;

// LeetCode 414 — Third Maximum Number: Track three distinct maximum values in one pass using constant space; skip duplicates and return the third largest if it exists, otherwise return the maximum.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int x : nums) {
            if (x == first || x == second || x == third)
                continue;

            if (x > first) {
                third = second;
                second = first;
                first = x;
            } else if (x > second) {
                third = second;
                second = x;
            } else if (x > third) {
                third = x;
            }
        }

        return (third == LLONG_MIN) ? first : third;
    }
};