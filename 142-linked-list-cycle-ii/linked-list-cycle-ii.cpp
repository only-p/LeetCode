/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if(head==NULL )return NULL;
        ListNode *slow = head, *fast = head;
        int loop=0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                loop = 1;
                break;
            }
                
        }
       
        if (loop==0) return NULL;
        int cnt = 1;
        cout<<slow->val<<" ";
        while (slow->next != fast) {
            cnt++;
            slow = slow->next;
        }
        slow = head, fast = head;
        for (int i = 0; i < cnt; i++) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};