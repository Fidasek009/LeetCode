#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int max = *std::max_element(candies.begin(), candies.end());
        std::vector<bool> out;

        for(int n : candies) out.push_back((n+extraCandies < max) ? false : true);
        return out;
    }
};


int main()
{
    std::vector<int> inp1 = {2,3,5,1,3};
    int inp2 = 3;
    Solution s = Solution();
    auto res = s.kidsWithCandies(inp1, inp2);
    for(bool n : res) std::cout << n << ", ";
    return 0;
}