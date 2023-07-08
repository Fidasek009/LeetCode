#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // create `set` from `nums1`
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> out;

        // check if elements match
        for(int x : nums2){
            if(set.find(x) != set.end()){
                out.push_back(x);
                set.erase(x);
            }
        } 

        return out;
    }
};

int main()
{
    vector<int> a = {4,9,5};
    vector<int> b = {9,4,9,8,4};
    Solution s = Solution();
    auto res = s.intersection(a, b);
    for(int x : res) cout << x << ", ";
    return 0;
}