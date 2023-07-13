#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++){
            if(map.find(nums[i]) != map.end() && i - map[nums[i]] < k+1) return true;
            else map[nums[i]] = i;
        }

        return false;
    }
};

int main()
{
    vector<int> a = {1,2,3,1};
    int b = 3;
    Solution s = Solution();
    auto res = s.containsNearbyDuplicate(a, b);
    cout << res;
    return 0;
}