#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while(i < nums.size() && nums[i] < target) i++;
        return i;
    }
};

int main()
{
    vector<int> a = {1,3,5,6};
    int b = 5;
    Solution s = Solution();
    auto res = s.searchInsert(a, b);
    cout << res;
    return 0;
}