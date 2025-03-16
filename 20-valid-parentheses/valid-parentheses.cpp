class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.size()==0)return false;
                char t = st.top();
                if ((t == '(' && s[i] == ')') || (t == '{' && s[i] == '}') ||
                    (t == '[' && s[i] == ']')) {
                    st.pop();
                }else return false;
            }
        }
        return st.size() == 0;
    }
};