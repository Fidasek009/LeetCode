#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0, left=0, right=0;
        bool set[128] = {0};

        while(right < s.length()){
            if(set[s[right]]) set[s[left++]] = false;
            else set[s[right++]] = true;
            if(right-left > longest) longest = right-left;
        }
        return longest;
    }
};

int main()
{
    string a = "abcabcbb";
    Solution s = Solution();
    auto res = s.lengthOfLongestSubstring(a);
    cout << res;
    return 0;
}