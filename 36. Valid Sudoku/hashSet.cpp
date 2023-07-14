#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> set;

        // check rows
        for(int i = 0; i < 9; i++){
            set.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(set.find(board[i][j]) == set.end()) set.insert(board[i][j]);
                    else return false;
                }
            }
        }

        // check columns
        for(int j = 0; j < 9; j++){
            set.clear();
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(set.find(board[i][j]) == set.end()) set.insert(board[i][j]);
                    else return false;
                }
            }
        }

        // check squares
        for(int a = 0; a < 9; a+=3){
            for(int b = 0; b < 9; b+=3){
                set.clear();
                // iterate in the square from top left corner
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[a+i][b+j] != '.'){
                            if(set.find(board[a+i][b+j]) == set.end()) set.insert(board[a+i][b+j]);
                            else return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    // vector<vector<char>> a = {{'5','3','.','.','7','.','.','.','.'}
    //                          ,{'6','.','.','1','9','5','.','.','.'}
    //                          ,{'.','9','8','.','.','.','.','6','.'}
    //                          ,{'8','.','.','.','6','.','.','.','3'}
    //                          ,{'4','.','.','8','.','3','.','.','1'}
    //                          ,{'7','.','.','.','2','.','.','.','6'}
    //                          ,{'.','6','.','.','.','.','2','8','.'}
    //                          ,{'.','.','.','4','1','9','.','.','5'}
    //                          ,{'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> a = {{'8','3','.','.','7','.','.','.','.'}
                             ,{'6','.','.','1','9','5','.','.','.'}
                             ,{'.','9','8','.','.','.','.','6','.'}
                             ,{'8','.','.','.','6','.','.','.','3'}
                             ,{'4','.','.','8','.','3','.','.','1'}
                             ,{'7','.','.','.','2','.','.','.','6'}
                             ,{'.','6','.','.','.','.','2','8','.'}
                             ,{'.','.','.','4','1','9','.','.','5'}
                             ,{'.','.','.','.','8','.','.','7','9'}};

    Solution s = Solution();
    auto res = s.isValidSudoku(a);
    cout << res;
    return 0;
}