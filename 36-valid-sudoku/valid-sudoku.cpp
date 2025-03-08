class Solution {

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