#include <vector>
#include <iostream>


class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for(unsigned int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};


int main(int argc, char const *argv[])
{
    std::vector inp = {1,2,3,4};
    Solution s = Solution();
    std::vector<int> res = s.runningSum(inp);

    for(unsigned int i = 0; i < res.size(); i++){
        std::cout << res[i] << ", ";
    }
    return 0;
}
