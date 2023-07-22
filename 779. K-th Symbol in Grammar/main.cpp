#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int mid = pow(2, n-1)/2;
        return (mid < k) ? !kthGrammar(n-1, k-mid) : kthGrammar(n-1, k);
    }
};

int main()
{
    auto a = 2;
    auto b = 1;
    Solution s = Solution();
    auto res = s.kthGrammar(a, b);
    cout << res;
    return 0;
}

/*
0
0|1
01|10
0110|1001
01101001|10010110
0110100110010110|1001011001101001
*/