/**
 * Problem: Intersection of Two Linked Lists
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach:
 * - Use two pointers, one starting from each list.
 * - When a pointer reaches the end of its list, redirect it to the head of the other list.
 * - If the lists intersect, the pointers will meet at the intersection node.
 * - If they do not intersect, both pointers will eventually become NULL at the same time.
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;

        if (headA == NULL || headB == NULL)
            return NULL;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1;
    }
};