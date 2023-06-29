#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out(2);
        unordered_map<int, int> map;
        // create a map of the array
        for(int i = 0; i < numbers.size(); i++) if(map.find(numbers[i]) == map.end()) map[numbers[i]] = i;

        for(auto x : map) {
            if(map.find(target-x.first) != map.end()){
                out = {x.second+1, map[target-x.first]+1};
                if(out[0] == out[1]) out[1]++;
                else if(out[0] > out[1]) swap(out[0], out[1]);
                return out;
            }
        }
        return out;
    }
};

int main()
{
    vector<int> a = {2,7,11,15};
    int b = 9;

    Solution s = Solution();
    auto res = s.twoSum(a, b);
    cout << res[0] << ", " << res[1];
    return 0;
}