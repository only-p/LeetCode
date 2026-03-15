class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s1.size(); i++)
            m1[s1[i]]++;
        int low = 0;
        bool ans = false;
        for (int i = 0; i < s2.size(); i++) {
            if (i < s1.size()-1)
                m2[s2[i]]++;
            else {
                m2[s2[i]]++;
                for (int j = 0; j < s1.size(); j++) {
                    if (m1[s1[j]] != m2[s1[j]])
                        break;
                    if (j == s1.size() - 1)
                        return true;
                }
                if (m2[s2[low]] == 1)
                    m2.erase(s2[low]);
                else
                    m2[s2[low]]--;
                low++;
            }
        }
        return false;
    }
};