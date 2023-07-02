#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
        for(int x : nums) set.insert(x);
        for(int i = 1; ; i++) if(set.find(i) == set.end()) return i;
    }
};

int main()
{
    vector<int> a = {3,4,-1,1};
    // vector<int> a = {1,2,0};
    // vector<int> a = {7,8,9,11,12};
    Solution s = Solution();
    auto res = s.firstMissingPositive(a);
    cout << res;
    return 0;
}