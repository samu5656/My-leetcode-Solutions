/*
-------------------------------------------------------
Problem: 143. Reorder List
Link: https://leetcode.com/problems/reorder-list/

Approach:
1. Find the middle of the linked list using the slow and fast pointer technique.
2. Split the list into two halves.
3. Reverse the second half of the list.
4. Merge the two halves alternately:
      First node -> Last node -> Second node -> Second Last node -> ...
5. The list is reordered in-place without using extra space.

Why it works:
- The slow and fast pointers locate the middle efficiently.
- Reversing the second half allows easy access to nodes from the end.
- Alternately merging both halves produces the required ordering.

Time Complexity: O(n)
- Finding the middle: O(n)
- Reversing the second half: O(n)
- Merging the two halves: O(n)

Overall: O(n)

Space Complexity: O(1)
- Only a few pointers are used.

-------------------------------------------------------
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        // Edge case:
        // No reordering needed for empty or single-node lists.
        if (!head || !head->next)
            return;

        // Step 1: Find the middle of the linked list.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list into two halves.
        ListNode *second = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse the second half.
        ListNode *prev = nullptr;

        while (second)
        {
            ListNode *nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        // Step 4: Merge the two halves alternately.
        ListNode *first = head;
        second = prev;

        while (second)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};