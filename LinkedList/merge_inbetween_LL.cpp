/**
 * Problem: Merge In Between Linked Lists
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/merge-in-between-linked-lists/
 *
 * Algorithm:
 * Linked List Manipulation
 *
 * Approach:
 * 1. Traverse list1 to find the node just before index 'a'.
 * 2. Starting from that node, move (b - a + 2) steps to reach the node
 *    immediately after index 'b'.
 * 3. Traverse list2 to find its last node.
 * 4. Connect:
 *      - node before 'a' -> head of list2
 *      - tail of list2 -> node after 'b'
 * 5. Return the modified list1.
 *
 * Time Complexity: O(n + m)
 *   - O(n) to traverse list1
 *   - O(m) to find the tail of list2
 *
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* curr = list1;
        ListNode* tail = list2;

        // Find the last node of list2
        while (tail->next) {
            tail = tail->next;
        }

        // Move to the node just before index 'a'
        for (int i = 0; i < a - 1; i++) {
            curr = curr->next;
        }

        // Find the node immediately after index 'b'
        ListNode* after = curr;
        for (int i = 0; i < b - a + 2; i++) {
            after = after->next;
        }

        // Connect the node before 'a' to list2
        curr->next = list2;

        // Connect the tail of list2 to the remaining part of list1
        tail->next = after;

        return list1;
    }
};