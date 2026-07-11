#include <vector>
using namespace std;

/*
===========================================================
LeetCode 867. Transpose Matrix
===========================================================

Problem:
Given a 2D integer matrix, return its transpose.

The transpose of a matrix is obtained by converting all rows into
columns and all columns into rows.

Approach:
- Let the original matrix have m rows and n columns.
- Create a new matrix of size n × m.
- Traverse each position in the transposed matrix and assign:
      result[i][j] = matrix[j][i]
- Return the transposed matrix.

Time Complexity : O(m × n)
Space Complexity: O(m × n)
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> result(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = matrix[j][i];
            }
        }

        return result;
    }
};