#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> out;
    string d;

    void gen(string seq, int n){
        if(n == d.length()) return out.push_back(seq);

        for(char x : chars[d[n]-50]){
            string newSeq = seq;
            newSeq.push_back(x);
            gen(newSeq, n+1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        d = digits;
        gen("", 0);
        return out;
    }
};

int main()
{
    string a = "23";
    Solution s = Solution();
    auto res = s.letterCombinations(a);
    for(string x : res) cout << x << ", ";
    return 0;
}