#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        bool set[128] = {0};
        for(int c : jewels) set[c] = true;
        for(int c : stones) if(set[c]) count++;
        return count;
    }
};

int main()
{
    string a = "aA";
    string b = "aAAbbbb";
    Solution s = Solution();
    auto res = s.numJewelsInStones(a, b);
    cout << res;
    return 0;
}