#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<map<int, int>> row(9), column(9), subgrid(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    column[j][num] = 1;
                    subgrid[(i / 3) * 3 + (j / 3)][num] = 1;
                }
            }
        }

        helper(0, 0, board, row, column, subgrid);
    }

    bool helper(int r, int c, vector<vector<char>>& board, vector<map<int, int>>& row, vector<map<int, int>>& column, vector<map<int, int>>& subgrid) {
        if(r == 9) {
            for(auto& it: board) {
                for(auto& i: it) {
                    cout << i << " ";
                }
                cout << endl;
            }
            return true;
        }

        if(c == 9) {
            return helper(r + 1, 0, board, row, column, subgrid);
        }

        if(board[r][c] != '.') {
            return helper(r, c + 1, board, row, column, subgrid);
        }

        for(int i = 1; i <= 9; i++) {
            int gridIndex = (r / 3) * 3 + (c / 3);

            if(row[r].find(i) == row[r].end() && column[c].find(i) == column[c].end() && subgrid[gridIndex].find(i) == subgrid[gridIndex].end()) {
                board[r][c] = i + '0';
                row[r][i] = 1;
                column[c][i] = 1;
                subgrid[gridIndex][i] = 1;

                if(helper(r, c + 1, board, row, column, subgrid)) {
                    return true;
                }

                board[r][c] = '.';
                row[r].erase(i);
                column[c].erase(i);
                subgrid[gridIndex].erase(i);
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '.', '9', '8', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '6', '.', '.', '.', '.', '2', '8'},
        {'.', '.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution sol;
    sol.solveSudoku(sudoku);
    return 0;
}
