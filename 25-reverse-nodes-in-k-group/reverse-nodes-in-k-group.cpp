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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1)
            return head;

        ListNode *current = head, *prev = NULL;

        // Count the length of the linked list
        int length = 0;
        while (current) {
            length++;
            current = current->next;
        }

        current = head;

        // Reverse in groups
        while (length >= k) {
            ListNode* lastNodeofPrevList = prev;
            ListNode* lastNodeOfSubList = current;
            ListNode* next = NULL;
            
            // prev = NULL;

            // Reverse `k` nodes
            for (int i = 0; i < k; i++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            if (lastNodeofPrevList) {
                lastNodeofPrevList->next = prev;
            } else {
                head = prev; // Update the head of the entire list
            }

            lastNodeOfSubList->next = current;

            prev = lastNodeOfSubList;
            length -= k;
        }

        return head;
    }
};