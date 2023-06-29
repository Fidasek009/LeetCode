#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        
        // sum every second element
        for(int i = 0; i < nums.size(); i += 2) sum += nums[i];

        return sum;
    }
};

int main()
{
    // vector<int> a = {1,4,3,2};
    vector<int> a = {6,2,6,5,1,2};
    Solution s = Solution();
    auto res = s.arrayPairSum(a);
    cout << res;
    return 0;
}