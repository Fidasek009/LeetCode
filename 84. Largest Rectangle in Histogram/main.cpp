#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    }
};

int main()
{
    // vector<int> a = {2,1,5,6,2,3};
    vector<int> a = {3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
    Solution s = Solution();
    auto res = s.largestRectangleArea(a);
    cout << res;
    return 0;
}