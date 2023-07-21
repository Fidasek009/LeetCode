#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double res = myPow(x, n/2);
        return (n%2 == 0) ? res * res : res * res * x;
    }

    double myPow(double x, int n) {
        if(n < 0) return pow(1/x, abs(n));
        return pow(x, n);
    }
};

int main()
{
    // auto a = 2;
    // auto b = 10;
    auto a = 2.1;
    auto b = 3;
    // auto a = 2;
    // auto b = -2;
    // auto a = 0.00001;
    // auto b = 2147483647;
    Solution s = Solution();
    auto res = s.myPow(a, b);
    cout << res;
    return 0;
}