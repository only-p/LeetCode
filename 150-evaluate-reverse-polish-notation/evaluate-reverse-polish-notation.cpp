class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            string x = tokens[i];
            if (x == "+") {

                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(a + b);
            } else if (x == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            } else if (x == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            } else if (x == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                s.push(b / a);
            } else {
                string x = tokens[i];
               
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};