#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int c = hours.size();
        for(int x : hours) if(x < target) c--;
        return c;
    }
};

int main()
{
    vector<int> a = {0,1,2,3,4};
    int b = 2;
    Solution s = Solution();
    auto res = s.numberOfEmployeesWhoMetTarget(a, b);
    cout << res;
    return 0;
}