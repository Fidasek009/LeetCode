#include <vector>
#include <iostream>

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num != 0)
        {
            if(num % 2 == 0) num /= 2;
            else num--;
            count++;
        }
        return count;
    }
};

int main()
{
    auto inp = 14;
    Solution s = Solution();
    auto res = s.numberOfSteps(inp);
    std::cout << res;
    return 0;
}