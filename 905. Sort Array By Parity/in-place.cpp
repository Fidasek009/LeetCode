#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even=0, odd=nums.size()-1;

        while(even < odd){
            while(even < odd && nums[even] % 2 == 0) even++;
            while(odd > even && nums[odd] % 2 == 1) odd--;

            int tmp = nums[even];
            nums[even++] = nums[odd];
            nums[odd--] = tmp;
        }

        return nums;
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