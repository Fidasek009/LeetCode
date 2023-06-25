#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out(numRows);

        for(int i = 0; i < numRows; i++){
            out[i] = {1};

            // generate first half of row
            for(int j = 1; j < i/2+1; j++) out[i].push_back(out[i-1][j] + out[i-1][j-1]);

            // append the flipped half
            out[i].insert(out[i].end(), out[i].rbegin()+(i%2==0), out[i].rend());
        }

        return out;
    }
};

int main()
{
    int a = 5;
    Solution s = Solution();
    auto res = s.generate(a);
    for(vector<int> x : res){
        for(int y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}