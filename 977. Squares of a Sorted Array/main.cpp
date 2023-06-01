#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int left=0, right=nums.size()-1, i=right;
        vector<int> out(nums.size());

        while(left < right+1){
            out[i--] = (abs(nums[left]) < nums[right]) ? pow(nums[right--], 2) : pow(nums[left++], 2);
        }

        return out;
    }
};

int main()
{
    //vector a = {-4,-1,0,3,10};
    //vector a = {-7,-3,2,3,11};
    //vector a = {-4,-4,-3};
    //vector a = {1};
    //vector a = {-4,-3,-3,-2,2};
    vector a = {-1,2,2};
    Solution s = Solution();
    auto res = s.sortedSquares(a);
    for(int n : res) cout << n << ", ";
    return 0;
}