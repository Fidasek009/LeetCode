#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> out = nums;
        out.insert(out.end(), nums.begin(), nums.end());
        return out;
    }
};

int main()
{
    vector<int> a = {1,2,3};
    Solution s = Solution();
    auto res = s.getConcatenation(a);
    for(int x : res) cout << x << ", ";
    return 0;
}