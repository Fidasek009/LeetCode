#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // make the numbers on num[x-1] negative to mark seen numbers
        for(int x : nums) if(nums[abs(x)-1] > 0) nums[abs(x)-1] *= -1;
        vector<int> out;
        // find what indexes aren't negative
        for(int i = 0; i < nums.size(); i++) if(nums[i] > 0) out.push_back(i+1);
        return out;
    }
};

int main()
{
    vector<int> a = {4,3,2,7,8,2,3,1}; // 5,6
    Solution s = Solution();
    auto res = s.findDisappearedNumbers(a);
    for(int x : res) cout << x << ", ";
    return 0;
}