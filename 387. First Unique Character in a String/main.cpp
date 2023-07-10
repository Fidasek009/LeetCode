#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chars(26, 0);

        // count up all the chars
        for(char x : s) chars[x - 97]++;
        // find the first unique char
        for(int i = 0; i < s.length(); i++) if(chars[s[i] - 97] == 1) return i;

        return -1;
    }
};

int main()
{
    string a = "aabb";
    Solution s = Solution();
    auto res = s.firstUniqChar(a);
    cout << res;
    return 0;
}