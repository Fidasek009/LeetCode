#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int lower, higher;
        if(nums[0] < nums[1]) lower=0, higher=1;
        else lower=1, higher=0;
        
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > nums[higher]){
                lower = higher;
                higher = i;
            }
            else if(nums[i] > nums[lower]) lower = i;
            
        }

        return (nums[higher]+1 > nums[lower]*2) ? higher : -1;
    }
};

int main()
{
    // vector a = {3,6,1,0};
    vector a = {10,3,5,1};
    // vector a = {1,2,3,4};
    // vector a = {1,0};
    // vector a = {0,1};
    // vector a = {0,2,0,3};
    Solution s = Solution();
    auto res = s.dominantIndex(a);
    cout << res;
    return 0;
}