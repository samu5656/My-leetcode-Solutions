#include <iostream>
#include <vector>
using namespace std;

// Intuition
// The number is represented as an array of digits, so converting it into an integer
// is unsafe due to possible overflow. Instead, we simulate adding 1 starting from
// the last digit and handle carry propagation.

// Approach
// Traverse the array from the last digit to the first.
// - If the current digit is less than 9, increment it and return.
// - If the digit is 9, set it to 0 and continue (carry).
// If all digits are 9, insert 1 at the beginning.

// Complexity
// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1) extra space (in-place modification).

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Driver code for VS Code testing
int main() {
    Solution sol;

    vector<int> digits = {9, 9, 9};
    vector<int> result = sol.plusOne(digits);

    cout << "Result: ";
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
