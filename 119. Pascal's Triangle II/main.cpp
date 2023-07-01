#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> out(n+1);

        for(int i = 0; i < n+1; i++){
            out[i] = {1};

            // generate first half of row
            for(int j = 1; j < i/2+1; j++) out[i].push_back(out[i-1][j] + out[i-1][j-1]);

            // append the last element
            if(i%2==1 && i != n) out[i].push_back(out[i].back());
        }

        out[n].insert(out[n].end(), out[n].rbegin()+(n%2==0), out[n].rend());

        return out[n];
    }
};

int main()
{
    auto a = 3;
    Solution s = Solution();
    auto res = s.getRow(a);
    for(int x : res) cout << x << ", ";
    return 0;
}