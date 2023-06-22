#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> out;
        int m=0, n=0, size=mat.size()*mat[0].size();

        // matrix is only 1 tall
        if(mat.size() == 1){
            out.insert(out.begin(), mat[0].begin(), mat[0].end());
            return out;
        }

        // go until end
        while(m*n < size){
            // go up right
            while(m > -1 && n < mat[0].size()) out.push_back(mat[m--][n++]);
            // turn around
            m++;
            if(n == mat[0].size()){
                m++;
                n--;
            }

            // go down left
            while(n > -1 && m < mat.size()) out.push_back(mat[m++][n--]);
            // turn around
            n++;
            if(m == mat.size()){
                n++;
                m--;
            }
        }

        return out;
    }
};

int main()
{   
    // [0,0], [0,1], [1,0], [2,0], [1,1], [0,2], [1,2], [2,1], [2,2]
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}}; // 1,2,4,7,5,3,6,8,9
    // vector<vector<int>> a = {{1}};
    Solution s = Solution();
    auto res = s.findDiagonalOrder(a);
    for(int x : res) cout << x << ", ";
    return 0;
}