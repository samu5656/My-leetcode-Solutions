/**
 * Problem: 206. Reverse Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-linked-list/
 *
 * Algorithm:
 * Iterative Three-Pointer Technique
 *
 * Approach:
 * - Initialize three pointers:
 *      1. prev -> Points to the previous node.
 *      2. curr -> Points to the current node.
 *      3. next -> Temporarily stores the next node.
 * - Traverse the linked list while updating the next pointer of each node
 *   to point to its previous node.
 * - Move all three pointers one step forward after each reversal.
 * - When traversal is complete, prev points to the new head of the reversed list.
 * - Return prev.
 *
 * Time Complexity: O(n)
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
    ListNode* reverseList(ListNode* head) {

        // Pointer to the previous node
        ListNode* prev = nullptr;

        // Pointer to the current node
        ListNode* curr = head;

        // Temporarily stores the next node
        ListNode* next = nullptr;

        // Traverse the linked list
        while (curr != nullptr) {

            // Save the next node
            next = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = next;
        }

        // prev is the new head of the reversed list
        return prev;
    }
};