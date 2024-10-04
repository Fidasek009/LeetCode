#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int n;
    vector<bool> cols;
    vector<bool> diagonal_x;
    vector<bool> diagonal_y;
    vector<string> board;
    vector<vector<string>> results;

    void init(int x) {
        n = x;
        cols = vector<bool>(x, false);
        diagonal_x = vector<bool>(x+x, false);
        diagonal_y = vector<bool>(x+x, false);
        board = vector<string>(n, string(n, '.'));
    }

    void solve_aux(int row) {
        if (row == n) {
            results.emplace_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (
                cols[col] ||
                diagonal_x[row + col] ||
                diagonal_y[row - col + (n-1)]
               )
                continue;

            cols[col] = true;
            diagonal_x[row + col] = true;
            diagonal_y[row - col + (n-1)] = true;
            board[row][col] = 'Q';
            solve_aux(row + 1);
            board[row][col] = '.';
            diagonal_y[row - col + (n-1)] = false;
            diagonal_x[row + col] = false;
            cols[col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        solve_aux(0);
        return results;
    }
};


void print_board(vector<string> board) {
    for (string line : board) {
            for (char c : line) {
                cout << c << ' ';
            }
            cout << endl;
        }
}

int main()
{
    auto a = 4;
    Solution s = Solution();
    auto res = s.solveNQueens(a);

    for (vector<string> sol : res) {
        cout << "----------" << endl;
        print_board(sol);
    }

    cout << "Found " << res.size() << " solutions." << endl;
    return 0;
}
