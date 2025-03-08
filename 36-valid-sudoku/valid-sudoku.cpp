class Solution {
private:
    bool row(int x, int y, vector<vector<char>>& board,
             unordered_map<char, int> m) {
        for (int i = x; i < 9; i++) {
            if (m[board[i][y]] == 0)
                return false;
            m[board[i][y]]--;
        }
        return true;
    }
    bool col(int x, int y, vector<vector<char>>& board,
             unordered_map<char, int> m) {
        for (int i = y; i < 9; i++) {
            if (m[board[x][i]] == 0)
                return false;
            m[board[x][i]]--;
        }
        return true;
    }
    bool mat(int x, int y, vector<vector<char>>& board,
             unordered_map<char, int> m) {
        for (int i = x; i < x + 3; i++) {
            if (i >= 9)
                continue;
            for (int j = y; j < y + 3; j++) {
                if (j >= 9)
                    continue;
                cout<<i<<'-'<<"-"<<m[board[i][j]];
                if (m[board[i][j]] == 0)
                    return false;
                m[board[i][j]]--;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current != '.') {
                    if (seen.count(current)) {
                        return false;
                    }
                    seen.insert(current);
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                char current = board[i][j];
                if (current != '.') {
                    if (seen.count(current)) {
                        return false;
                    }
                    seen.insert(current);
                }
            }
        }

        // Check 3x3 subgrids
        for (int block = 0; block < 9; block++) {
            unordered_set<char> seen;
            for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {
                for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
                    char current = board[i][j];
                    if (current != '.') {
                        if (seen.count(current)) {
                            return false;
                        }
                        seen.insert(current);
                    }
                }
            }
        }

        return true;
    
    }
};