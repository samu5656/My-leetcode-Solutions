/**
 * Problem: Delete the Middle Node of a Linked List
 * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 *
 * Approach:
 * - Handle the edge case where the list has only one node.
 * - Use the slow and fast pointer technique to find the middle node.
 * - Maintain a previous pointer to the node before the middle.
 * - Delete the middle node by updating the previous node's next pointer.
 * - Free the memory occupied by the deleted node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

// Definition for local compilation
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);

    return head;
}

int main() {
    // Driver code can be added here for testing.
    return 0;
}