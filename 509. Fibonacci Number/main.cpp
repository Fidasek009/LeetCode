#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> map = {{0,0},{1,1}};

    int fib(int n) {
        if(map.find(n) != map.end()) return map[n];
        map[n] = fib(n-1) + fib(n-2);
        return map[n];
    }
};

int main()
{
    int a = 2;
    Solution s = Solution();
    int res = s.fib(a);
    cout << res;
    return 0;
}