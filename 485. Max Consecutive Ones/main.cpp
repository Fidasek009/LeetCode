#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        
        for(int n : nums){
            if(n == 1) count++;
            else{
                if(max < count) max = count;
                count=0;
            }
        }
        return (max < count) ? count : max;
    }
};

int main()
{
    vector a = {1,0,1,1,0,1};
    Solution s = Solution();
    auto res = s.findMaxConsecutiveOnes(a);
    cout << res;
    return 0;
}