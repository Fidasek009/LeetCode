#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> reachable(n-1, false);

        for(int i = edges.size()-1; i > -1; i--){
            reachable[edges[i][1]] = true;
            edges.pop_back();
        }

        vector<int> out;
        for(int i = 0; i < n; i++){
            if(!reachable[i]) out.push_back(i);
        }

        return out;
    }
};

int main()
{
    int inp1 = 5;
    //vector<vector<int>> inp2 = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    vector<vector<int>> inp2 = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    Solution s = Solution();
    auto res = s.findSmallestSetOfVertices(inp1, inp2);
    for(int n : res) cout << n;
    return 0;
}