#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string opening = "([{";
        string closing = ")]}";
        stack<char> lifo;


        for(char n : s){
            if(opening.find(n) < 3) lifo.push(n);
            else{
                int x = closing.find(n);
                if(x < 3 && !lifo.empty() && lifo.top() == opening[x]) lifo.pop();
                else return false;
            }
        }

        return lifo.empty();
    }
};

int main()
{
    auto inp = "}";
    Solution s = Solution();
    auto res = s.isValid(inp);
    cout << res;
    return 0;
}