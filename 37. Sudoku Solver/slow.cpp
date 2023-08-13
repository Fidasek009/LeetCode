#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<char> FULLSET = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

struct Cell {
    char val;
    unordered_set<char> options;
    Cell(char x = '.') : val(x), options(FULLSET) {}
};

class Board {
private:
    bool plot(int x, int y, char n){
        // element already filled
        if(board[y][x].val != '.') return true;

        // remove option
        board[y][x].options.erase(n);

        // return false if there are more options
        return board[y][x].options.size() != 0;
    }

public:
    Cell board[9][9];

    Board(){}


    Board(vector<vector<char>>& brd){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(brd[i][j] != '.')
                    place(j, i, brd[i][j]);
    }


    bool place(int x, int y, char n){
        board[y][x].val = n;

        // validate row
        for(int i = 0; i < 9; i++)
            if(!plot(i, y, n))
                return false;

        // validate column
        for(int i = 0; i < 9; i++)
            if(!plot(x, i, n))
                return false;

        // validate square
        x = (x/3)*3;
        y = (y/3)*3;
        for(int i = y; i < y+3; i++)
            for(int j = x; j < x+3; j++)
                if(!plot(j, i, n))
                    return false;

        return true;
    }


    void convert(vector<vector<char>>& brd){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(brd[i][j] == '.')
                    brd[i][j] = board[i][j].val;
    }
};


class Solution {
private:
    Board solved;
    bool done = false;

    void solve(Board &brd, int x, int y){
        // iterate row
        if(x > 8){
            y++;
            // board complete
            if(y > 8){
                solved = brd;
                done = true;
                return;
            }

            x = 0;
        }

        // already filled -> place the next element
        if(brd.board[y][x].val != '.') return solve(brd, x+1, y);
        
        for(char c : brd.board[y][x].options){
            // board complete
            if(done) return;
            // duplicate board
            Board b = brd;
            // try to place element
            if(!b.place(x, y, c)) continue;
            // place next element
            solve(b, x+1, y);
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        Board B = Board(board);
        solve(B, 0, 0);
        solved.convert(board);
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