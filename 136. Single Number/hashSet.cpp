#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;

        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) == set.end()) set.insert(nums[i]);
            else set.erase(nums[i]);
        }

        return *(set.begin());
    }
};

int main()
{
    vector<int> a = {4,1,2,1,2};
    Solution s = Solution();
    auto res = s.singleNumber(a);
    cout << res;
    return 0;
}