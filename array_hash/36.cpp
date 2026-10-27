#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][9] = {};
        bool c[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int digit = board[i][j] - '1';
                int box = (i / 3) * 3 + j / 3;

                if (r[i][digit] ||
                    c[j][digit] ||
                    boxes[box][digit]) {
                    return false;
                }

                r[i][digit] = true;
                c[j][digit] = true;
                boxes[box][digit] = true;
            }
        }

        return true;
    }
};
