#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) if(nums[i-1] == nums[i]) return true;
        return false;
    }
};

int main()
{
    vector<int> a = {1,2,3,1};
    Solution s = Solution();
    auto res = s.containsDuplicate(a);
    cout << res;
    return 0;
}