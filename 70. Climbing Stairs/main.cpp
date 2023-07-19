#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        
        vector<int> comb(n);
        comb[0] = 1;
        comb[1] = 2;

        for(int i = 2; i < n; i++) comb[i] = comb[i-1] + comb[i-2];

        return comb[n-1];
    }
};

int main()
{
    auto a = 1;
    Solution s = Solution();
    auto res = s.climbStairs(a);
    cout << res;
    return 0;
}