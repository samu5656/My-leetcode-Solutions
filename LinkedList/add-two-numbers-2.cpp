/**
 * Problem: 445. Add Two Numbers II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers-ii/
 *
 * Algorithm:
 * Stack + Linked List
 *
 * Approach:
 * - Push all digits from both linked lists into two stacks.
 * - Pop digits from the stacks to simulate addition from the least
 *   significant digit.
 * - Maintain a carry during the addition.
 * - Create each new node at the front of the result list.
 * - Return the head of the newly constructed list.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Stacks to store digits of both numbers
        stack<int> s1, s2;

        // Push digits of the first number
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push digits of the second number
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        // Stores carry generated during addition
        int carry = 0;

        // Head of the resultant linked list
        ListNode* head = nullptr;

        // Continue until both stacks are empty and no carry remains
        while (!s1.empty() || !s2.empty() || carry) {

            int sum = carry;

            // Add top digit from the first stack
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            // Add top digit from the second stack
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Create a new node for the current digit
            ListNode* node = new ListNode(sum % 10);

            // Insert the node at the front of the result list
            node->next = head;
            head = node;

            // Update carry for the next iteration
            carry = sum / 10;
        }

        // Return the head of the resultant list
        return head;
    }
};