/**
 * Problem: 2. Add Two Numbers
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Algorithm:
 * Linked List Traversal + Carry Simulation
 *
 * Approach:
 * - Create a dummy node to simplify the construction of the result list.
 * - Traverse both linked lists simultaneously.
 * - At each step:
 *      1. Read the current digit from each list (0 if the list has ended).
 *      2. Add the digits along with the carry from the previous addition.
 *      3. Create a new node containing the last digit of the sum.
 *      4. Update the carry.
 * - After traversal, if a carry remains, append it as a new node.
 * - Return the list starting from dummy.next.
 *
 * Time Complexity: O(max(n, m))
 * Space Complexity: O(max(n, m))
 */


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify result list construction
        ListNode dummy(0);
        ListNode* curr = &dummy;

        // Stores carry generated during addition
        int carry = 0;

        // Pointers to traverse both linked lists
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // Traverse until both lists are exhausted
        while (temp1 || temp2) {

            // Current digit from each list (0 if list has ended)
            int x = temp1 ? temp1->val : 0;
            int y = temp2 ? temp2->val : 0;

            // Compute sum including carry
            int sum = x + y + carry;

            // Update carry for the next iteration
            carry = sum / 10;

            // Append the current digit to the result list
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move to the next nodes
            if (temp1)
                temp1 = temp1->next;

            if (temp2)
                temp2 = temp2->next;
        }

        // Append the remaining carry if present
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        // Return the head of the result list
        return dummy.next;
    }
};