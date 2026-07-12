/*
=========================================
LeetCode 59. Spiral Matrix II
=========================================

Problem:
Given a positive integer n, generate an n × n matrix filled with elements
from 1 to n² in spiral order.

Time Complexity: O(n²)
Space Complexity: O(1) Extra Space (excluding the output matrix)

*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        vector<vector<int>> result(n, vector<int>(n));
        int a = 1;

        while (left <= right && top <= bottom) {

            // Traverse Left → Right
            for (int i = left; i <= right; i++) {
                result[top][i] = a++;
            }
            top++;

            // Traverse Top → Bottom
            for (int i = top; i <= bottom; i++) {
                result[i][right] = a++;
            }
            right--;

            // Traverse Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = a++;
                }
                bottom--;
            }

            // Traverse Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = a++;
                }
                left++;
            }
        }

        return result;
    }
};