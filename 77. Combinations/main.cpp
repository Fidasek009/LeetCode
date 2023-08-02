#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> combinations;

    void gen(int n, int k, vector<int> &seq){
        if(k == 0) return combinations.push_back(seq);

        for(int i = n; i > 0; i--){
            vector<int> newSeq = seq;
            newSeq.push_back(i);
            if(i > k-1) gen(i-1, k-1, newSeq);
            else break;
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        gen(n, k, v);
        return combinations;
    }
};

int main()
{
    // int a = 4;
    // int b = 2;
    int a = 3;
    int b = 3;
    Solution s = Solution();
    auto res = s.combine(a, b);
    for(vector<int> v : res){
        for(int x : v) cout << x << ", ";
        cout << endl;
    }
    return 0;
}