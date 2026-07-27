/**
 * Problem: Delete Node in a Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 *
 * Algorithm:
 * Copy the value of the next node into the current node,
 * then bypass the next node.
 *
 * Approach:
 * Since the head of the linked list is not provided, we cannot
 * access the previous node to perform a normal deletion.
 * Instead:
 * 1. Copy the value of the next node into the current node.
 * 2. Update the current node's next pointer to skip the next node.
 * This effectively removes the desired node from the list.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node's value into the current node
        node->val = node->next->val;

        // Skip the next node
        node->next = node->next->next;
    }
};