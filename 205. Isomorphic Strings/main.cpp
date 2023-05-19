#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;

        for(int i = 0; i < s.size(); i++){
            // char not in map AND it is its 1st ocurrance
            if(map.find(s[i]) == map.end() && t.find(t[i]) == i) map[s[i]] = t[i];
            // mapped characters dont correspond
            else if(map[s[i]] != t[i]) return false;
        }

        return true;
    }
};

int main()
{
    string inp1 = "badc";
    string inp2 = "baba";
    Solution s = Solution();
    auto res = s.isIsomorphic(inp1, inp2);
    cout << res;
    return 0;
}