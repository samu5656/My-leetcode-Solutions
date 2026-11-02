// # 1019. Next Greater Node In Linked List

// - **Problem:** Next Greater Node In Linked List
// - **Difficulty:** Medium
// - **Link:** https://leetcode.com/problems/next-greater-node-in-linked-list/
// - **Algorithm:** Monotonic Decreasing Stack
// - **Approach:** Convert the linked list into an array. Use a monotonic decreasing stack to store indices. For every element, pop indices whose corresponding values are smaller than the current element and update their next greater value in the result array. Elements without a greater element remain 0.
// - **Time Complexity:** O(n) – Each index is pushed and popped at most once.
// - **Space Complexity:** O(n) – Array, result vector, and stack.

// ### Code (C++)



//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        // Step 1: Convert linked list into an array
        vector<int> num;
        ListNode* curr = head;

        while (curr != nullptr) {
            num.push_back(curr->val);
            curr = curr->next;
        }

        int n = num.size();

        // Step 2: Initialize result with 0
        vector<int> result(n, 0);

        // Step 3: Monotonic decreasing stack (stores indices)
        stack<int> st;

        for (int i = 0; i < n; i++) {

            // Find the next greater element for previous indices
            while (!st.empty() && num[st.top()] < num[i]) {

                int index = st.top();
                st.pop();

                result[index] = num[i];
            }

            // Push current index
            st.push(i);
        }

        return result;
    }
};

// ### Example

// **Input:** `2 → 1 → 5`

// **Output:** `[5, 5, 0]`

// ### Key Learning
// - Use a monotonic decreasing stack.
// - Store indices instead of values to update the correct positions.
// - Each index is pushed and popped at most once, giving O(n) time complexity.