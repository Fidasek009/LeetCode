#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int xy = 0) {
        int i = xy,
            j = xy,
            m = matrix[0].size()-1,
            n = matrix.size()-1;

        // out of bounds
        if(xy > m || xy > n) return false;

        // check x axis
        while(i < m && matrix[xy][i] < target) i++;
        if(matrix[xy][i] == target) return true;

        // check y axis
        while(j < n && matrix[j][xy] < target) j++;
        if(matrix[j][xy] == target) return true;

        // recursion
        if(i != xy || j != xy) return searchMatrix(matrix, target, xy+1);
        return false;
    }
};

int main()
{
    // vector<vector<int>> a = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int b = 30;
    // vector<vector<int>> a = {{-5}};
    // int b = -2;
    vector<vector<int>> a = {{-1},{-1}};
    int b = 2;
    Solution s = Solution();
    auto res = s.searchMatrix(a, b);
    cout << res;
    return 0;
}