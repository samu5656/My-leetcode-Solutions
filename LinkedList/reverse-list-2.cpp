/*
===========================================================
Problem    : 92. Reverse Linked List II
Difficulty : Medium
Link       : https://leetcode.com/problems/reverse-linked-list-ii/

Algorithm  : Head Insertion

Approach:
1. Create a dummy node pointing to the head.
2. Move `prev` to the node just before the `left` position.
3. Let `curr` be the first node of the sublist to reverse.
4. Repeatedly remove the node after `curr` and insert it immediately
   after `prev`.
5. Repeat (right - left) times.
6. Return dummy.next.

Time Complexity : O(n)
Space Complexity: O(1)
===========================================================
*/


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // No reversal needed
        if (head == nullptr || left == right)
            return head;

        // Dummy node simplifies edge cases (e.g., reversing from head)
        ListNode dummy(0, head);

        // Move prev to the node before 'left'
        ListNode* prev = &dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // First node of the sublist
        ListNode* curr = prev->next;

        // Reverse using head insertion
        for (int i = 0; i < right - left; i++) {

            // Node to move to the front
            ListNode* nextNode = curr->next;

            // Remove nextNode from its current position
            curr->next = nextNode->next;

            // Insert nextNode immediately after prev
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};