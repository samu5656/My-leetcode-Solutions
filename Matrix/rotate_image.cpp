#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
=========================================
LeetCode 48. Rotate Image
=========================================

Problem:
You are given an n × n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise) in-place.

Time Complexity: O(n²)
Space Complexity: O(1)

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};