#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Determine if a number is a Happy Number
 * 
 * Approach:
 * - Repeatedly replace the number with the sum of squares of its digits
 * - Use a hash set to detect cycles
 * - If the number becomes 1 → Happy Number
 * - If a number repeats → cycle detected → Not Happy
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
class Solution {
public:

    // Function to compute sum of squares of digits
    int nextint(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int t = n % 10;
            sum += t * t;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        // Loop until number becomes 1 or a cycle is detected
        while (seen.find(n) == seen.end() && n != 1)
        {
            seen.insert(n);
            n = nextint(n);
        }

        return n == 1;
    }
};