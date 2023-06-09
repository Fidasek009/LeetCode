#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int m = matrix.size()-1,                    // height
            n = matrix[0].size()-1,                 // width
            size = matrix.size()*matrix[0].size(),  // total element count
            y = 0,                                  // starting y position
            x = -1;                                 // starting x position
            
            

        while(out.size() < size){
            // →
            while(x < n && matrix[y][x+1] < 128) {
                out.push_back(matrix[y][++x]);
                matrix[y][x] = 128;
            }
            // ↓
            while(y < m && matrix[y+1][x] < 128) {
                out.push_back(matrix[++y][x]);
                matrix[y][x] = 128;
            }
            // ←
            while(x > 0 && matrix[y][x-1] < 128) {
                out.push_back(matrix[y][--x]);
                matrix[y][x] = 128;
            }
            // ↑
            while(y > 0 && matrix[y-1][x] < 128) {
                out.push_back(matrix[--y][x]);
                matrix[y][x] = 128;
            }
        }

        return out;
    }
};

int main()
{
    // vector<vector<int>> a = {{0}};
    // vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}}; // 1,2,3,6,9,8,7,4,5
    vector<vector<int>> a = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; // 1,2,3,4,8,12,11,10,9,5,6,7
    Solution s = Solution();
    auto res = s.spiralOrder(a);
    for(int x : res) cout << x << ", ";
    return 0;
}