#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Valid Sudoku

    Goal:
    Determine if a 9x9 Sudoku board is valid.

    Rules:
    1. Each row must contain digits 1-9 without repetition.
    2. Each column must contain digits 1-9 without repetition.
    3. Each 3x3 sub-box must contain digits 1-9 without repetition.

    Note:
    - Empty cells are represented by '.'
    - Only filled cells need validation
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Create 9 sets for rows, columns, and boxes
        vector<unordered_set<char>> row(9), col(9), box(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                char current = board[i][j];

                // Skip empty cells
                if(current == '.') continue;

                // Calculate 3x3 box index
                int box_index = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if(row[i].count(current) ||
                   col[j].count(current) ||
                   box[box_index].count(current)) {
                    return false;
                }

                // Insert into sets
                row[i].insert(current);
                col[j].insert(current);
                box[box_index].insert(current);
            }
        }

        return true;
    }
};