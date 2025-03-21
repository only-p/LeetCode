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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode *current = head, *prev=NULL;
        while (i < left) {
            prev = current;
            current = current->next;
            i++;
        }
        ListNode* next = NULL;
        ListNode* lastNodeofFirstPart = prev;
        ListNode* lastNodeofList = current;
        while (i <= right) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            i++;
        }
        if (lastNodeofFirstPart!=NULL) {
            lastNodeofFirstPart->next = prev;
        } else
            head = prev;

        lastNodeofList->next = current;
        return head;
    }
};