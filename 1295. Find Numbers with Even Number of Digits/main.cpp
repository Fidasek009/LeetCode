#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int findNumbers(const vector<int>& nums) {
        int res = 0;

        for(const int n : nums){
            // find out number of digits with math
            for(int i = 0; i < 6; i++){
                int p = pow(10, i);
                // n is less than 10 when dividing
                if(n / p < 10){
                    // i+1 is number of digits
                    if(i % 2 == 1) res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector a = {12,345,2,6,7896};
    Solution s = Solution();
    auto res = s.findNumbers(a);
    cout << res;
    return 0;
}