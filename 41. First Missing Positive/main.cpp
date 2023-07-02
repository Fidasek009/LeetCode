#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // eliminate negative numbers and 0
        for(int i = 0; i < n; i++) if(nums[i] < 1) nums[i] = n+1;
        // negate numbers on indexes where numbers are found
        for(int x : nums) if(x < n+1 && nums[abs(x)-1] > 0) nums[abs(x)-1] *= -1;
        // find the first positive index
        for(int i = 0; i < n; i++) if(nums[i] > 0) return i+1;
        return n+1;
    }
};

int main()
{
    vector<int> a = {3,4,-1,1};
    // vector<int> a = {1,2,0};
    // vector<int> a = {7,8,9,11,12};
    Solution s = Solution();
    auto res = s.firstMissingPositive(a);
    cout << res;
    return 0;
}