#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
=========================================
LeetCode 289. Game of Life
=========================================

Problem:
According to Conway's Game of Life, compute the next state of the board
in-place without using an additional board.

Time Complexity: O(R × C)
Space Complexity: O(1)

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int R = board.size();
        int C = board[0].size();

        vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        // Mark the cells based on the next state
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                int live = 0;

                // Count live neighbors
                for (int k = 0; k < 8; k++) {
                    if (isValid(dx[k] + i, dy[k] + j, R, C) &&
                        abs(board[dx[k] + i][dy[k] + j]) == 1) {
                        live++;
                    }
                }

                // Dead cell becomes alive
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;
                }

                // Live cell dies
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = -1;
                }
            }
        }

        // Finalize the board
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
            }
        }
    }

    bool isValid(int x, int y, int R, int C) {
        return (x >= 0 && x < R && y >= 0 && y < C);
    }
};