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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>m;
        if(head==NULL)return NULL;
        ListNode *node = head;
        m[head]+=1;
        while(node->next!=NULL){
            node = node->next;
            if(m.find(node)!=m.end())return node;
            m[node]+=1;
        }
        return NULL;
        
    }
};