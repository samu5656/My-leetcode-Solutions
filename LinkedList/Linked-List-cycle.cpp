/**
 * Problem: 142. Linked List Cycle II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Algorithm:
 * Floyd's Cycle Detection (Tortoise and Hare)
 *
 * Approach:
 * - Use two pointers (slow and fast) to detect whether a cycle exists.
 * - Move slow by one step and fast by two steps.
 * - If they meet, a cycle is present.
 * - Reset slow to the head of the list while keeping fast at the meeting point.
 * - Move both pointers one step at a time.
 * - The node where they meet again is the starting node of the cycle.
 * - If fast reaches nullptr, no cycle exists.
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
    ListNode* detectCycle(ListNode* head) {

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Detect whether a cycle exists
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {

                // Move slow to the head
                slow = head;

                // Find the starting node of the cycle
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Return the starting node of the cycle
                return slow;
            }
        }

        // No cycle found
        return nullptr;
    }
};