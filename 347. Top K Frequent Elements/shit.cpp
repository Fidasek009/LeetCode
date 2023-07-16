#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        if(nums.size() == 1) return {nums[0]};

        unordered_map<int, vector<int>> map;
        priority_queue<int> pq;
        sort(nums.begin(), nums.end());

        // create a map of count
        for(int i = 0; i < nums.size()-1; i++){
            int c = 1;
            while(nums[i] == nums[i+1] && i++ < nums.size()) c++;
            map[c].push_back(nums[i]);
            pq.push(c);
        }

        vector<int> out;
        while(out.size() < k) {
            out.insert(out.end(), map[pq.top()].begin(), map[pq.top()].end());
            pq.pop();
        }

        return out;
    }
};

int main()
{
    // vector<int> a = {1,1,1,2,2,3};
    // int b = 2;
    // vector<int> a = {1};
    // int b = 1;
    vector<int> a = {-1,-1};
    int b = 1;
    Solution s = Solution();
    auto res = s.topKFrequent(a, b);
    for(int x : res) cout << x << ", ";
    return 0;
}