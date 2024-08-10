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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;

        // Find the length of the linked list
        ListNode* current = head;
        int n = 1; // Start with 1 to account for the head node itself
        while (current->next) {
            current = current->next;
            n++;
        }
        current->next = head;
        k = k % n;
        int stepsToNewHead = n - k;

        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            newTail = newTail->next;
        }
        head = newTail->next;

        // Break the circular linked list
        newTail->next = nullptr;

        return head;
    }
};