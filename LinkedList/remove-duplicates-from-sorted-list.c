/**
 * Problem: Remove Duplicates from Sorted List
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach:
 * - Traverse the sorted linked list using a pointer.
 * - If the current node and the next node have the same value,
 *   remove the duplicate node by updating the next pointer.
 * - Free the memory of the removed node.
 * - Otherwise, move to the next node.
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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            struct ListNode *dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    // Driver code can be added here for testing.
    return 0;
}