/**
 * Problem: 430. Flatten a Multilevel Doubly Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *
 * Algorithm:
 * Iterative Traversal + Pointer Manipulation
 *
 * Approach:
 * - Traverse the doubly linked list using a pointer (curr).
 * - Whenever a node has a child:
 *      1. Store the current node's next pointer.
 *      2. Find the tail of the child list.
 *      3. Connect the child list after the current node.
 *      4. Connect the tail of the child list to the stored next node.
 *      5. Update the prev pointers accordingly.
 *      6. Remove the child pointer by setting it to nullptr.
 * - Continue traversing until the end of the flattened list.
 * - Return the original head.
 *
 * Time Complexity: O(n²)  // Finding the tail for every child may require repeated traversal.
 * Space Complexity: O(1)
 */

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {

        // Pointer to traverse the list
        Node* curr = head;

        while (curr) {

            // Process only if the current node has a child
            if (curr->child) {

                // Store the next node
                Node* next = curr->next;

                // Find the tail of the child list
                Node* tail = curr->child;
                while (tail->next) {
                    tail = tail->next;
                }

                // Connect the child list after the current node
                curr->next = curr->child;
                curr->child->prev = curr;

                // Connect the tail of the child list to the stored next node
                tail->next = next;

                // Update the previous pointer of the next node
                if (next) {
                    next->prev = tail;
                }

                // Remove the child pointer
                curr->child = nullptr;
            }

            // Move to the next node
            curr = curr->next;
        }

        // Return the flattened list
        return head;
    }
};