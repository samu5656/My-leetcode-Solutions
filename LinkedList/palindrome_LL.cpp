/**
 * Problem: 234. Palindrome Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Algorithm:
 * Fast & Slow Pointer + In-place Linked List Reversal
 *
 * Approach:
 * - If the list has zero or one node, it is already a palindrome.
 * - Use the fast and slow pointer technique to find the middle of the list.
 * - Reverse the second half of the linked list.
 * - Compare the first half with the reversed second half node by node.
 * - If all corresponding values match, the list is a palindrome.
 * - Otherwise, return false.
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
    bool isPalindrome(ListNode* head) {

        // Empty list or single-node list is always a palindrome
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Compare the first half with the reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {

            // Mismatch found
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        // All nodes matched
        return true;
    }
};