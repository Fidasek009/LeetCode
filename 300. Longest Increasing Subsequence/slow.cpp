#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int max = 0;
    vector<int> ammounts;

    void count(vector<int>& nums, int n, int x){
        if(x > max) max = x;

        if(n+1 > nums.size()) return;

        if(x < ammounts[n]+1) return;
        ammounts[n] = x;

        for(int i = n+1; i < nums.size(); i++){
            if(nums[i] > nums[n]) count(nums, i, x+1);
            else count(nums, i, 1);
        }
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        ammounts = vector(nums.size(), 0);
        count(nums, 0, 1);
        return max;
    }
};

int main()
{
    // vector<int> a = {10,9,2,5,3,7,101,18};   // 4
    // vector<int> a = {0,1,0,3,2,3};           // 4
    vector<int> a = {7,7,7,7,7,7,7};         // 1
    // vector<int> a = {3,1,2};                 // 2
    // vector<int> a = {0,1,2,3,4,5};           // 6
    // vector<int> a = {-1,-2,-3,-4,-5};        // 1
    Solution s = Solution();
    auto res = s.lengthOfLIS(a);
    cout << endl << res;
    return 0;
}