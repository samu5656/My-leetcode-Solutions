/*
    Problem: Remove Nth Node From End of List
    LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    Difficulty: Medium
    Topic: Linked List, Two Pointers
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

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
