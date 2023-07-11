#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> out;

        // fiil `map`
        for(int x : nums1) {
            if(map.find(x) == map.end()) map[x] = 1;
            else map[x]++;
        }

        for(int x : nums2) {
            if(map.find(x) != map.end() && map[x] > 0) {
                map[x]--;
                out.push_back(x);
            }
        }

        return out;
    }
};

int main()
{
    vector<int> a = {1,2,2,1};
    vector<int> b = {2,2};
    Solution s = Solution();
    auto res = s.intersect(a, b);
    for(int x : res) cout << x << ", ";
    return 0;
}