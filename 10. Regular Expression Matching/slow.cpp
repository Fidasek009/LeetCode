#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int sl = s.length();
        const int pl = p.length();

        // both need to be empty to return true
        if(pl == 0) return sl == 0;

        const bool firstMatch = sl > 0 && (p[0] == s[0] || p[0] == '.');

        // has star
        if(pl > 1 && p[1] == '*')
            return isMatch(s, p.substr(2, pl)) || firstMatch && isMatch(s.substr(1, sl), p);
        
        // doesn't have star
        return firstMatch && isMatch(s.substr(1, sl), p.substr(1, pl));
    }
};

int main()
{
    string str = "";
    string reg = "";
    Solution s = Solution();
    auto res = s.isMatch(str, reg);
    cout << res;
    return 0;
}