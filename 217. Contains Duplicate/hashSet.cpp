#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) != set.end()) return true;
            else set.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    vector<int> a = {1,2,3,1};
    Solution s = Solution();
    auto res = s.containsDuplicate(a);
    cout << res;
    return 0;
}