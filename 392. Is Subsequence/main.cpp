#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(j < t.length() && i < s.length()){
            if(s[i] == t[j]) i++;
            j++;
        }
        
        return (i == s.length());
    }
};

int main()
{
    string a = "abc";
    string b = "ahbgdc";
    Solution s = Solution();
    auto res = s.isSubsequence(a, b);
    cout << res;
    return 0;
}