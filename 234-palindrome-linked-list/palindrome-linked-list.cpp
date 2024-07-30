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
 ListNode * reverse(ListNode* head){
    ListNode *prev = NULL, *current = head, *next ;
        while (current != NULL) {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
        }
        return prev;

 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverse(slow);
        slow = head;
        while(fast && slow){
            if(fast->val != slow->val)return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
        
    }
};