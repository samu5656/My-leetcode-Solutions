#include <iostream>
#include <vector>
using namespace std;

/*
=========================================
LeetCode 498. Diagonal Traverse
=========================================

Problem:
Given an m x n matrix, return all elements of the matrix in diagonal order.

Time Complexity: O(m × n)
Space Complexity: O(1) Extra Space (excluding the output vector)

*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();

        int row = 0, col = 0;
        bool up = true;

        vector<int> result;

        while (row < m && col < n) {

            if (up) {

                // Traverse Up-Right
                while (row > 0 && col < n - 1) {
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }

                result.push_back(mat[row][col]);

                if (col == n - 1) {
                    row++;
                } else {
                    col++;
                }

            } else {

                // Traverse Down-Left
                while (col > 0 && row < m - 1) {
                    result.push_back(mat[row][col]);
                    row++;
                    col--;
                }

                result.push_back(mat[row][col]);

                if (row == m - 1) {
                    col++;
                } else {
                    row++;
                }
            }

            up = !up;
        }

        return result;
    }
};