#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=1, max=nums.back();
        for(int i = nums.size()-2; i > -1 && c < 3; i--){
            if(nums[i] < max){
                max = nums[i];
                c++;
            }
        }

        return (c < 3) ? nums.back() : max;
    }
};

int main()
{
    vector<int> a = {3,2,1}; // 1
    // vector<int> a = {5,2,2}; // 5
    // vector<int> a = {1,2}; // 2
    Solution s = Solution();
    auto res = s.thirdMax(a);
    cout << res;
    return 0;
}