#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i+=2) if(nums[i-1] != nums[i]) return nums[i-1];
        return nums.back();
    }
};

int main()
{
    vector<int> a = {4,1,2,1,2};
    Solution s = Solution();
    auto res = s.singleNumber(a);
    cout << res;
    return 0;
}