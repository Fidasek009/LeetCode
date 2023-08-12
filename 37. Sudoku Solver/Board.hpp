#include <vector>
#include <unordered_set>
#include <iostream>

#pragma once

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
        // remove option
        board[y][x].options.erase(n);

        // no more options left
        short size = board[y][x].options.size();
        if(size == 0) return false;

        // if there is only one option left, try and place it
        if(size == 1)
            if(!place(x, y, *board[y][x].options.begin()))
                return false;
        
        return true;
    }

public:
    Cell board[9][9];

    Board(){}


    Board(vector<vector<char>>& brd){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(brd[i][j] != '.'){
                    board[i][j].options.clear();
                    if(!place(j, i, brd[i][j]))
                        printf("x: %d, y: %d, c: %c\n", j, i, brd[i][j]);
                }
                    
    }


    bool place(int x, int y, char n){
        board[y][x].val = n;

        // validate row
        for(int i = 0; i < 9; i++)
            if(board[y][i].val == '.')
                if(!plot(i, y, n)) {
                    board[y][x].val = '.';
                    return false;
                }

        // validate column
        for(int i = 0; i < 9; i++)
            if(board[i][x].val == '.')
                if(!plot(x, i, n)) {
                    board[y][x].val = '.';
                    return false;
                }

        // validate square
        for(int i = (y/3)*3; i < y+3; i++)
            for(int j = (x/3)*3; j < x+3; j++)
                if(board[i][j].val == '.')
                    if(!plot(j, i, n)) {
                        board[y][x].val = '.';
                        return false;
                    }

        // place value
        board[y][x].val = n;

        return true;
    }


    void convert(vector<vector<char>>& brd){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                //if(brd[i][j] == '.')
                brd[i][j] = board[i][j].val;
    }
};