#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool remainder = true;
        int i = digits.size()-1;

        while(i > -1){
            if(digits[i] == 9) digits[i] = 0;
            else {
                digits[i]++;
                remainder = false;
                break;
            }
            i--;
        }

        if(remainder) digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    // vector<int> a = {4,3,2,1};
    vector<int> a = {9};
    Solution s = Solution();
    auto res = s.plusOne(a);
    for(int x : res) cout << x;
    return 0;
}