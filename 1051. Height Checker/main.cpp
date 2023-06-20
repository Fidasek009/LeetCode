#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());

        for(int i = 0; i < heights.size(); i++)
            if(heights[i] != expected[i])
                count++;

        return count;
    }
};

int main()
{
    vector a = {1,1,4,2,1,3};
    Solution s = Solution();
    auto res = s.heightChecker(a);
    cout << res;
    return 0;
}