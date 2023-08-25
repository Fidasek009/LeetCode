#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> OUT;

    void gen(int n, int m, string s){
        if(n == 0 && m == 0) OUT.push_back(s);

        if(n > 0) gen(n-1, m, s+'(');
        if(m > n) gen(n, m-1, s+')');
    }

public:
    vector<string> generateParenthesis(int n) {
        gen(n, n, "");
        return OUT;
    }
};

int main()
{
    auto a = 3;
    Solution s = Solution();
    auto res = s.generateParenthesis(a);
    for(string s : res) cout << s << ", ";
    return 0;
}