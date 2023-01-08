#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

#define BOX 3
#define BOARD 9
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[BOARD][BOARD];
        int cols[BOARD][BOARD];
        int boxs[BOX][BOX][BOARD];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxs, 0, sizeof(boxs));

        for (int i = 0; i < BOARD; i++) {
            for (int j = 0; j < BOARD; j++) {
                char c = board[i][j];
                if (c != '.') {
                    c = c - '1';
                    if (rows[i][c] == 0) rows[i][c]++;
                    else return false;
                    if (cols[j][c] == 0) cols[j][c]++;
                    else return false;
                    if (boxs[i / BOX][j / BOX][c] == 0) boxs[i / BOX][j / BOX][c]++;
                    else return false;
                }
            }
        }
        return true;
    }
};

