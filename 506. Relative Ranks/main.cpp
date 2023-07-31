#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        string medals[3] = {"Gold Medal","Silver Medal","Bronze Medal"};

        // fill priority queue with [value, position] pair
        for(int i = 0; i < score.size(); i++) pq.push({score[i], i});

        // fill out array
        vector<string> out(score.size());
        while(!pq.empty()) {
            int place = score.size()-pq.size();
            out[pq.top().second] = (place < 3) ? medals[place] : to_string(place+1);
            pq.pop();
        }

        return out;
    }
};

int main()
{
    // vector<int> a = {10,3,8,9,4};
    vector<int> a = {5,4,3,2,1};
    Solution s = Solution();
    auto res = s.findRelativeRanks(a);
    for(string x : res) cout << x << ", ";
    return 0;
}