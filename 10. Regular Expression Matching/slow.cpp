#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // both need to be empty to return true
        if(p.empty()) return s.empty();

        // wherther the 1st char matches
        const bool firstMatch = !s.empty() && (p[0] == s[0] || p[0] == '.');

        // has star
        if(p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p);
        
        // doesn't have star
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

int main()
{
    string str = "aaa";
    string reg = "ab*a*c*a";
    Solution s = Solution();
    auto res = s.isMatch(str, reg);
    cout << res;
    return 0;
}