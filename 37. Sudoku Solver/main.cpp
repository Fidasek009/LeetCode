#include <iostream>
#include <vector>

using namespace std;


class Board {
private:
    bool row[9][9];
    bool col[9][9];
    bool box[9][9];
    char board[9][9];
    bool done = false;

    bool place(short x, short y, short n){
        // box position
        short z = (y/3)*3 + x/3;
        // check if element can be placed
        if(row[y][n] && col[x][n] && box[z][n]){
            row[y][n] = false;
            col[x][n] = false;
            box[z][n] = false;
        } 
        else return false;

        // place element
        board[y][x] = n + 49;

        return true;
    }


    void remove(short x, short y) {
        short n = board[y][x] - 49;
        board[y][x] = '.';

        row[y][n] = true;
        col[x][n] = true;
        box[(y/3)*3 + x/3][n] = true;
    }

public:
    Board(){}

    Board(vector<vector<char>>& brd){
        // initialize board and sets
        for(short i = 0; i < 9; i++){
            for(short j = 0; j < 9; j++){
                row[i][j] = true;
                col[i][j] = true;
                box[i][j] = true;
                board[i][j] = '.';
            }
        }

        // place board
        for(short i = 0; i < 9; i++)
            for(short j = 0; j < 9; j++)
                if(brd[i][j] != '.')
                    place(j, i, brd[i][j] - 49);
    }


    void convert(vector<vector<char>>& brd){
        for(short i = 0; i < 9; i++)
            for(short j = 0; j < 9; j++)
                if(brd[i][j] == '.')
                    brd[i][j] = board[i][j];
    }


    void solve(short x, short y){
        // iterate row
        if(x > 8){
            y++;
            // board complete
            if(y > 8){
                done = true;
                return;
            }

            x = 0;
        }

        // already filled -> place the next element
        if(board[y][x] != '.') return solve(x+1, y);

        // try to place 1-9
        for(short i = 0; i < 9; i++){
            if(place(x, y, i)){
                solve(x+1, y);
                if(!done) remove(x, y);
                else return;
            }
        }
    }
};


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Board B = Board(board);
        B.solve(0, 0);
        B.convert(board);
    }
};

int main()
{
    // vector<vector<char>> a = {{'5','3','.','.','7','.','.','.','.'},    // {{'5','3','4','6','7','8','9','1','2'},
    //                           {'6','.','.','1','9','5','.','.','.'},    //  {'6','7','2','1','9','5','3','4','8'},
    //                           {'.','9','8','.','.','.','.','6','.'},    //  {'1','9','8','3','4','2','5','6','7'},
    //                           {'8','.','.','.','6','.','.','.','3'},    //  {'8','5','9','7','6','1','4','2','3'},
    //                           {'4','.','.','8','.','3','.','.','1'},    //  {'4','2','6','8','5','3','7','9','1'},
    //                           {'7','.','.','.','2','.','.','.','6'},    //  {'7','1','3','9','2','4','8','5','6'},
    //                           {'.','6','.','.','.','.','2','8','.'},    //  {'9','6','1','5','3','7','2','8','4'},
    //                           {'.','.','.','4','1','9','.','.','5'},    //  {'2','8','7','4','1','9','6','3','5'},
    //                           {'.','.','.','.','8','.','.','7','9'}};   //  {'3','4','5','2','8','6','1','7','9'}}

    vector<vector<char>> a = {{'.','.','9','7','4','8','.','.','.'},
                              {'7','.','.','.','.','.','.','.','.'},
                              {'.','2','.','1','.','9','.','.','.'},
                              {'.','.','7','.','.','.','2','4','.'},
                              {'.','6','4','.','1','.','5','9','.'},
                              {'.','9','8','.','.','.','3','.','.'},
                              {'.','.','.','8','.','3','.','2','.'},
                              {'.','.','.','.','.','.','.','.','6'},
                              {'.','.','.','2','7','5','9','.','.'}};

    Solution s = Solution();
    s.solveSudoku(a);
    for(vector<char> v : a){
        cout << endl;
        for(char c : v) cout << c << "  ";
    }
    return 0;
}