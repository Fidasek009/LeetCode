#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> permutations;

    void gen(unordered_set<int> &set, vector<int> &sequence){
        if(set.size() == 0) return permutations.push_back(sequence);

        for(int x : set){
            unordered_set newSet = set;
            newSet.erase(x);
            vector<int> newSeq = sequence;
            newSeq.push_back(x);
            gen(newSet, newSeq);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> v;
        gen(set, v);
        return permutations;
    }
};

int main()
{
    // vector<int> a = {1,2,3};
    vector<int> a = {0,1};
    Solution s = Solution();
    auto res = s.permute(a);
    for(vector<int> v : res){
        for(int x : v) cout << x << ", ";
        cout << endl;
    }
    return 0;
}