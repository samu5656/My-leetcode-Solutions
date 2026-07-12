/*
=========================================
LeetCode 54. Spiral Matrix
=========================================

Problem:
Given an m x n matrix, return all elements of the matrix in spiral order.

Time Complexity: O(m × n)
Space Complexity: O(1) Extra Space (excluding the output vector)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, top = 0;
        int right = m - 1, bottom = n - 1;

        vector<int> result;

        while (left <= right && top <= bottom) {

            // Traverse Left → Right
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // Traverse Top → Bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};