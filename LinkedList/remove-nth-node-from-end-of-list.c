/**
 * Problem: Remove Nth Node From End of List
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Approach:
 * - Create a dummy node pointing to the head to handle edge cases
 *   (such as deleting the first node).
 * - Initialize two pointers, fast and slow, at the dummy node.
 * - Move the fast pointer n steps ahead.
 * - Move both pointers together until fast reaches the last node.
 * - The slow pointer will be just before the node to be deleted.
 * - Remove the target node and free its memory.
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    struct ListNode *temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}

int main() {
    // Driver code can be added here for testing.
    return 0;
}