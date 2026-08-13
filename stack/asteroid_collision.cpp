/**
 * Problem: 735. Asteroid Collision
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/asteroid-collision/
 *
 * Algorithm:
 * Stack Simulation
 *
 * Approach:
 * - Use a vector as a stack to store the surviving asteroids.
 * - Traverse each asteroid from left to right.
 * - A collision can occur only when:
 *      1. The asteroid in the stack is moving right (`> 0`).
 *      2. The current asteroid is moving left (`< 0`).
 * - If the asteroid in the stack is smaller, remove it and continue checking.
 * - If both asteroids have the same size, remove the stack asteroid and
 *   destroy the current asteroid.
 * - If the stack asteroid is larger, destroy the current asteroid.
 * - If the current asteroid survives, push it onto the stack.
 * - Return the stack containing all surviving asteroids.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Vector used as a stack to store surviving asteroids
        vector<int> st;

        // Process each asteroid from left to right
        for (int a : asteroids) {

            // Indicates whether the current asteroid is destroyed
            bool destroyed = false;

            // Collision occurs only when the stack asteroid moves right
            // and the current asteroid moves left
            while (!st.empty() && st.back() > 0 && a < 0) {

                // Stack asteroid is smaller, so it gets destroyed
                if (st.back() < -a) {
                    st.pop_back();
                    continue;
                }

                // Both asteroids have the same size, so both are destroyed
                else if (st.back() == -a) {
                    st.pop_back();
                }

                // Current asteroid is destroyed
                destroyed = true;
                break;
            }

            // Add the current asteroid if it survived the collision
            if (!destroyed) {
                st.push_back(a);
            }
        }

        // Return all surviving asteroids
        return st;
    }
};