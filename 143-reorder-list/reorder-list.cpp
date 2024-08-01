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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *current = head, *next;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;
        while (firstHalf && secondHalf) {
            ListNode* temp = firstHalf->next;
            firstHalf->next = secondHalf;
            firstHalf = temp;

            temp = secondHalf->next;
            secondHalf->next = firstHalf;
            secondHalf = temp;
        }
        if (firstHalf)
            firstHalf->next = NULL;
    }
};