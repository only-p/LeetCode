/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        // vector<vector<int>> ans;
        if (root == NULL)
            return root;

        queue<Node*> pq;
        pq.push(root);
        while (!pq.empty()) {
            int levelsize = pq.size();
            vector<int> temp;
            for (int i = 0; i < levelsize; i++) {
                Node* node = pq.front();
                pq.pop();

                temp.push_back(node->val);
                if (node->left)
                    pq.push(node->left);
                if (node->right)
                    pq.push(node->right);

                if(i==levelsize-1)node->next =NULL;
                else{
                    node->next = pq.front();
                }
            }
           
        }
        return root;
    }
};