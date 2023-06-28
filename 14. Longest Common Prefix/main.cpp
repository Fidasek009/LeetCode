#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x;

        for(x = 0; x < strs[0].length(); x++){
            for(int y = 1; y < strs.size(); y++){
                if(strs[y][x] != strs[0][x]) return strs[0].substr(0, x);
            }
        }

        return strs[0].substr(0, x);
    }
};

int main()
{
    vector<string> a = {"a"};
    Solution s = Solution();
    auto res = s.longestCommonPrefix(a);
    cout << res;
    return 0;
}