#include <vector>
#include <iostream>


class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max = 0;
        int sum = 0;

        for(int i = accounts.size()-1; i >= 0; i--){
            sum = 0;
            for(auto& n : accounts[i]) sum+=n;
            accounts.pop_back();
            if(sum > max) max = sum;
        }
        return max;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> inp = {{2,8,7},{7,1,3},{1,9,5}};
    
    Solution s = Solution();

    int res = s.maximumWealth(inp);

    std::cout << res;
    return 0;
}
