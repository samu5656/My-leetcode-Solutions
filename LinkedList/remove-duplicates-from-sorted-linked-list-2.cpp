/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Problem: 82. Remove Duplicates from Sorted List II
 * Difficulty: Medium
 *
 * Approach:
 * - Create a dummy node before the head to handle cases where the
 *   first few nodes are duplicates.
 * - Maintain two pointers:
 *      1. prev -> Last confirmed unique node.
 *      2. curr -> Current node being processed.
 * - If duplicates are found, skip the entire duplicate group.
 * - Otherwise, move prev forward.
 * - Return dummy.next as the new head.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};