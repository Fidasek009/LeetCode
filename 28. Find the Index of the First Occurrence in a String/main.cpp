#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;

        while(i < haystack.length()){
            // match the `needle` to the current position in `haystack`
            while(j < needle.length() && haystack[i+j] == needle[j]) j++;
            // the needle fully matches
            if(j == needle.length()) return i;

            j=0;
            i++;
        }

        return -1;
    }
};

int main()
{
    string a = "butsa";
    string b = "sad";
    Solution s = Solution();
    auto res = s.strStr(a, b);
    cout << res;
    return 0;
}