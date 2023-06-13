#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

int main()
{   
    vector<int> a = {0,1,2,2,3,0,4,2};
    int b = 2;
    Solution s = Solution();
    auto res = s.removeElement(a, b);
    cout << res;
    return 0;
}

// made in 7 minutes and 22 seconds