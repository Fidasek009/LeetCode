#include <vector>
#include <iostream>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0, left = 0;

        for(int n : nums) sum += n;

        for(int i = 0; i < nums.size(); i++){
            left += nums[i];
            if(sum-left == left-nums[i]) return i;
        }

        return -1;
    }
};

int main()
{
    //std::vector<int> inp = {-1,-1,-1,0,1,1};
    //std::vector<int> inp = {2,1,-1};
    std::vector<int> inp = {1,7,3,6,5,6};
    Solution s = Solution();
    auto res = s.pivotIndex(inp);
    std::cout << res;
    return 0;
}