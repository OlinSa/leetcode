#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {

        int row_map[9][9];
        int columns_map[9][9];
        int boxes[3][3][9];

        memset(row_map, 0, sizeof(row_map));
        memset(columns_map, 0, sizeof(columns_map));
        memset(boxes, 0, sizeof(boxes));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int index = c - '0' -1;
                row_map[i][index]++;
                columns_map[j][index]++;
                boxes[i / 3][j / 3][index]++;
                if (row_map[i][index] > 1 || columns_map[j][index] > 1 || boxes[i / 3][j / 3][index] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    std::vector<std::vector<char>> case1{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::cout << s.isValidSudoku(case1) << std::endl;

    std::vector<std::vector<char>> case2{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << s.isValidSudoku(case2) << std::endl;
    return 0;
}