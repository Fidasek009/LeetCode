#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size()+1;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            int j = i;
            while(j < nums.size() && sum < target) sum+=nums[j++];
            if(sum+1 > target && j-i < min) min = j-i;
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