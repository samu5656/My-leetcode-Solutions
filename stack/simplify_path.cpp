#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
 * Problem: 71. Simplify Path
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/simplify-path/
 *
 * Algorithm:
 * Stack Simulation
 *
 * Approach:
 * - Use a vector<string> as a stack to store valid directory names.
 * - Use stringstream to split the path using '/' as the delimiter.
 * - Ignore empty parts and "." because they do not change the path.
 * - For "..", remove the most recent directory if the stack is not empty.
 * - For normal directory names, push them into the stack.
 * - Finally, build the canonical path by adding '/' before each directory.
 * - If the stack is empty, the canonical path is "/".
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    string simplifyPath(string path) {

        // Stack to store valid directory names
        vector<string> st;

        // Split the path using '/' as the delimiter
        stringstream ss(path);
        string part;

        // Process each component of the path
        while (getline(ss, part, '/')) {

            // Ignore empty components and current directory "."
            if (part.empty() || part == ".") {
                continue;
            }

            // ".." means move one directory back
            if (part == "..") {

                // Go back only if there is a directory to remove
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {

                // Store a valid directory name
                st.push_back(part);
            }
        }

        // Build the simplified canonical path
        string ans;

        for (string dir : st) {
            ans += "/" + dir;
        }

        // Root directory
        if (st.empty()) {
            return "/";
        }

        return ans;
    }
};