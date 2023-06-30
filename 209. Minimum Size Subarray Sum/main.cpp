#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size()+1, sum=nums[0], l=0, r=0;

        while(r < nums.size()-1){
            // element is >= to target
            if(nums[r++]+1 > target) return 1;
            sum += nums[r];
            // increase `r` increase `sum`
            while(r < nums.size()-1 && sum < target) sum += nums[++r];
            // increase `l` decrease `sum`
            while(l < nums.size()-1 && sum-nums[l]+1 > target) sum -= nums[l++];

            if(r+1-l < min && sum+1 > target) min = r+1-l;
        }

        return (min == nums.size()+1) ? 0 : min;
    }
};

int main()
{
    int a = 7; 
    vector<int> b = {2,3,1,2,4,3}; // 2
    Solution s = Solution();
    auto res = s.minSubArrayLen(a, b);
    cout << res;
    return 0;
}