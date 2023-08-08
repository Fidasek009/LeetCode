#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};

int main()
{
    vector<int> a = {0,5,8,2,8,4,6,4,6,7,2,6,2,7,3,8,1,6,2,4};
    Solution s = Solution();
    auto res = s.sortArray(a);
    for(int x : res) cout << x << ", ";
    return 0;
}