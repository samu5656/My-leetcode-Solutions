/**
 * Problem: 86. Partition List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/partition-list/
 *
 * Algorithm:
 * Two Dummy Lists
 *
 * Approach:
 * - Create two dummy linked lists:
 *      1. lessHead    -> Stores nodes with values less than x.
 *      2. greaterHead -> Stores nodes with values greater than or equal to x.
 * - Traverse the original list once.
 * - Append each node to the appropriate list based on its value.
 * - Connect the end of the 'less' list to the beginning of the 'greater' list.
 * - Set the last node of the 'greater' list to nullptr to avoid cycles.
 * - Return the head of the combined list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
    ListNode* partition(ListNode* head, int x) {

        // Dummy heads for the two partitions
        ListNode lessHead(0), greaterHead(0);

        // Tail pointers for each partition
        ListNode* lessPtr = &lessHead;
        ListNode* greaterPtr = &greaterHead;

        // Traverse the original list
        ListNode* curr = head;

        while (curr) {

            // Append node to the appropriate partition
            if (curr->val < x) {
                lessPtr->next = curr;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = curr;
                greaterPtr = greaterPtr->next;
            }

            curr = curr->next;
        }

        // Connect the two partitions
        lessPtr->next = greaterHead.next;

        // Mark the end of the list
        greaterPtr->next = nullptr;

        // Return the head of the partitioned list
        return lessHead.next;
    }
};