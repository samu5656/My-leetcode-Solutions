/*
-------------------------------------------------------
Problem: 328. Odd Even Linked List
Link: https://leetcode.com/problems/odd-even-linked-list/

Approach:
- Maintain two separate pointers:
  1. odd  -> points to nodes at odd positions.
  2. even -> points to nodes at even positions.
- Store the head of the even list (evenHead) so it can be attached later.
- Traverse the list while both even and even->next exist:
    - Link the current odd node to the next odd node.
    - Move the odd pointer forward.
    - Link the current even node to the next even node.
    - Move the even pointer forward.
- Finally, connect the end of the odd list to the head of the even list.

Why it works:
- The relative order of odd-positioned nodes remains unchanged.
- The relative order of even-positioned nodes also remains unchanged.
- Only the next pointers are modified, making the solution in-place.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(1)
- No extra data structures are used.

-------------------------------------------------------
*/

//   Definition for singly-linked list.
  struct ListNode
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution
  {
  public:
      ListNode *oddEvenList(ListNode *head)
      {

          // Edge case:
          // If the list is empty or contains only one node,
          // no rearrangement is required.
          if (head == nullptr || head->next == nullptr)
              return head;

          // Pointer to the first odd-positioned node.
          ListNode *odd = head;

          // Pointer to the first even-positioned node.
          ListNode *even = head->next;

          // Store the head of the even list for later attachment.
          ListNode *evenHead = even;

          // Rearrange odd and even nodes separately.
          while (even != nullptr && even->next != nullptr)
          {

              // Connect current odd node to the next odd node.
              odd->next = even->next;
              odd = odd->next;

              // Connect current even node to the next even node.
              even->next = odd->next;
              even = even->next;
          }

          // Attach the even list after the odd list.
          odd->next = evenHead;

          return head;
      }
  };