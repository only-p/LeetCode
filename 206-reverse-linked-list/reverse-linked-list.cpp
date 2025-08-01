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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = reverse(head->next);
        ListNode* newNext = head->next;
        newNext->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode* current = head;
        // ListNode* next = NULL;
        // ListNode* prev = NULL;
        // while(current  ){
        //     next = current->next;
        //    current->next = prev;
        //    prev = current;
        //    current = next;
        // }
        // return prev;

        return reverse(head);
    }
};