#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string out = "";
        for(char c : address) {
            if(c == '.') out.append("[.]");
            else out.push_back(c);
        }
        return out;
    }
};

int main()
{
    string a = "1.1.1.1";
    Solution s = Solution();
    auto res = s.defangIPaddr(a);
    cout << res;
    return 0;
}