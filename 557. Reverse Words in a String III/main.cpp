#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;

        while(i < s.length()){
            int l=i;
            // find space
            while(i < s.length() && s[i] != ' ') i++;
            // reverse word
            int r=i-1;
            while(l < r){
                char tmp = s[l];
                s[l++] = s[r];
                s[r--] = tmp;
            }
            i++;
        }

        return s;
    }
};

int main()
{
    auto a = "Let's take LeetCode contest";
    Solution s = Solution();
    auto res = s.reverseWords(a);
    cout << res;
    return 0;
}