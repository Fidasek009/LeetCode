#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i < j) {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }
};

int main()
{
    vector<char> a = {'h','e','l','l','o'};
    Solution s = Solution();
    s.reverseString(a);
    for(char x : a) cout << x;
    return 0;
}