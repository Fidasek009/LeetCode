#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    string a = "butsad";
    string b = "sad";
    Solution s = Solution();
    auto res = s.strStr(a, b);
    cout << res;
    return 0;
}