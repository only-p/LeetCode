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
        ListNode *temp1, *temp2;
        while (firstHalf && secondHalf) {
            temp1 = firstHalf->next;
            temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            firstHalf = temp1;

            secondHalf->next = firstHalf;
            secondHalf = temp2;
        }
        if (firstHalf)
            firstHalf->next = NULL;
    }
};