/**
 * Problem: 24. Swap Nodes in Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Algorithm:
 * Dummy Node + Pointer Manipulation
 *
 * Approach:
 * - Create a dummy node before the head to simplify swapping the first pair.
 * - Maintain a pointer (prev) to the node before the current pair.
 * - For each pair:
 *      1. Identify the first and second nodes.
 *      2. Update pointers to swap them.
 *      3. Move prev to the end of the swapped pair.
 * - Continue until fewer than two nodes remain.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // Dummy node to handle swapping involving the head
        ListNode dummy(0, head);

        // Points to the node before the current pair
        ListNode* prev = &dummy;

        // Process while at least two nodes are available
        while (prev->next && prev->next->next) {

            // First and second nodes of the current pair
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Perform the swap
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        // Return the new head
        return dummy.next;
    }
};