#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return myPow(1/x, abs(n));
        if(n == 0) return 1;
        if(n == 1) return x;
        return x * myPow(x, n-1);
    }
};

int main()
{
    // auto a = 2;
    // auto b = 10;
    // auto a = 2.1;
    // auto b = 3;
    // auto a = 2;
    // auto b = -2;
    auto a = 0.00001;
    auto b = 2147483647;
    Solution s = Solution();
    auto res = s.myPow(a, b);
    cout << res;
    return 0;
}