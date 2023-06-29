#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;

        // create a map of the array
        for(int i = 0; i < numbers.size(); i++) {
            if(map.find(target-numbers[i]) != map.end()) return {map[target-numbers[i]], i};
            map[numbers[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> a = {2,7,11,15};
    int b = 9;
    // vector<int> a = {2,4,11,3};
    // int b = 6;
    Solution s = Solution();
    auto res = s.twoSum(a, b);
    cout << res[0] << ", " << res[1];
    return 0;
}