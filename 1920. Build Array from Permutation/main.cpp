#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int> nums) {
        int n = nums.size();
        for(int &x : nums) x = x + n * (nums[x]%n);
        for(int &x : nums) x /= n;
        return nums;
    }
};

int main()
{
    // vector<int> a = {0,2,1,5,3,4};  // 0,1,2,4,5,3
    vector<int> a = {5,0,1,2,3,4};  // 4,5,0,1,2,3
    Solution s = Solution();
    auto res = s.buildArray(a);
    for(int x : res) cout << x << ", ";
    return 0;
}