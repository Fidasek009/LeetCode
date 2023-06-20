#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even=0, odd=nums.size()-1;
        vector<int> out(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0) out[even++] = nums[i];
            else out[odd--] = nums[i];
        }

        return out;
    }
};

int main()
{
    // vector<int> a = {3,1,2,4};
    vector<int> a = {0};
    Solution s = Solution();
    auto res = s.sortArrayByParity(a);
    for(int n : res) cout << n << ", ";
    return 0;
}