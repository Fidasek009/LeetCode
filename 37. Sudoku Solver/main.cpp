#include <iostream>
#include <vector>
#include <unordered_set>
#include "Board.hpp"

using namespace std;


class Solution {
private:
    Board solved;

    void solve(Board &brd, int x, int y){
        // iterate row
        if(x > 8){
            y++;
            // board complete
            if(y > 8){
                solved = brd;
                return;
            }

            x = 0;
        }

        if(brd.board[y][x].val != '.') return solve(brd, x+1, y);
        
        for(char c : brd.board[y][x].options){
            Board b = brd;
            if(!b.place(x, y, c)) continue;
            solve(b, x+1, y);
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        Board B = Board(board);
        // solve(B, 0, 0);
        B.convert(board);
    }
};

int main()
{
    vector<vector<char>> a = {{'5','3','.','.','7','.','.','.','.'},    // {{'5','3','4','6','7','8','9','1','2'},
                              {'6','.','.','1','9','5','.','.','.'},    //  {'6','7','2','1','9','5','3','4','8'},
                              {'.','9','8','.','.','.','.','6','.'},    //  {'1','9','8','3','4','2','5','6','7'},
                              {'8','.','.','.','6','.','.','.','3'},    //  {'8','5','9','7','6','1','4','2','3'},
                              {'4','.','.','8','.','3','.','.','1'},    //  {'4','2','6','8','5','3','7','9','1'},
                              {'7','.','.','.','2','.','.','.','6'},    //  {'7','1','3','9','2','4','8','5','6'},
                              {'.','6','.','.','.','.','2','8','.'},    //  {'9','6','1','5','3','7','2','8','4'},
                              {'.','.','.','4','1','9','.','.','5'},    //  {'2','8','7','4','1','9','6','3','5'},
                              {'.','.','.','.','8','.','.','7','9'}};   //  {'3','4','5','2','8','6','1','7','9'}}

    Solution s = Solution();
    s.solveSudoku(a);
    for(vector<char> v : a){
        cout << endl;
        for(char c : v) cout << c << "  ";
    }
    return 0;
}