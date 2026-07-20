/*
-------------------------------------------------------
Problem: 61. Rotate List
Link: https://leetcode.com/problems/rotate-list/

Approach:
- First, find the length of the linked list and the last node.
- Since rotating by n positions results in the same list,
  reduce the rotations using:
      k = k % n
- If k becomes 0, return the original list.
- Connect the last node to the head, forming a circular linked list.
- The new tail will be the (n - k - 1)th node from the beginning.
- The node after the new tail becomes the new head.
- Break the circular link to obtain the rotated list.

Why it works:
- Converting the list into a circular linked list allows rotation
  without repeatedly moving nodes.
- Finding the new tail correctly determines where the list should
  be split after rotation.

Time Complexity: O(n)
- One traversal to find the length.
- One traversal to find the new tail.

Space Complexity: O(1)
- Only a few pointers are used.

-------------------------------------------------------
*/

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases:
        // Empty list, single node, or no rotation needed.
        if (!head || !head->next || k == 0)
            return head;

        ListNode* curr = head;
        int n = 1;

        // Find the length of the list and the last node.
        while (curr->next) {
            n++;
            curr = curr->next;
        }

        // Reduce unnecessary rotations.
        k = k % n;

        // If no effective rotation is needed.
        if (k == 0)
            return head;

        // Form a circular linked list.
        curr->next = head;

        // Find the new tail.
        ListNode* tail = head;
        for (int i = 0; i < n - k - 1; i++) {
            tail = tail->next;
        }

        // The next node becomes the new head.
        ListNode* newHead = tail->next;

        // Break the circular linked list.
        tail->next = nullptr;

        return newHead;
    }
};