#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        // create a map of counted elements
        unordered_map<int, int> map;
        for(int x : nums) map[x]++;

        // priority queue of pair(count, element)
        priority_queue<pair<int, int>> pq;
        vector<int> out;

        for(pair<const int, const int> it : map){
            pq.push(make_pair(it.second, it.first));
            // queue has an element which is in the top `k` most frequent
            if(pq.size() > map.size()-k){
                out.push_back(pq.top().second);
                pq.pop();
            }
        }

        return out;
    }
};

int main()
{
    vector<int> a = {1,1,1,2,2,3};
    int b = 2;
    // vector<int> a = {1};
    // int b = 1;
    // vector<int> a = {-1,-1};
    // int b = 1;
    Solution s = Solution();
    auto res = s.topKFrequent(a, b);
    for(int x : res) cout << x << ", ";
    return 0;
}