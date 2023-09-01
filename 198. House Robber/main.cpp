#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int max;
    vector<int> ammounts;

    void count(int n, int x, vector<int>& nums){
        if(n+1 > nums.size()){
            if(x > max) max = x;
            return;
        }

        for(int i = n; i < nums.size(); i++){
            if(x + nums[i] > ammounts[i]){
                ammounts[i] = x + nums[i];
                count(i+2, ammounts[i], nums);
            }
        }
    }

public:
    int rob(vector<int>& nums) {
        ammounts = vector(nums.size(), 0);
        count(0, 0, nums);
        return max;
    }
};

int main()
{
    vector<int> a = {1,2,3,1};
    // vector<int> a = {2,7,9,3,1};
    Solution s = Solution();
    auto res = s.rob(a);
    cout << res;
    return 0;
}