#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};

int main()
{
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    Solution s = Solution();
    auto res = s.removeDuplicates(a);
    cout << res << endl;
    for(int n : a) cout << n << ", ";
    return 0;
}