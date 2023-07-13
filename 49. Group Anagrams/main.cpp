#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }

        vector<vector<string>> out;
        for(auto x : map) 
            out.push_back(x.second);

        return out;
    }
};

int main()
{
    vector<string> a = {"eat","tea","tan","ate","nat","bat"};
    Solution s = Solution();
    auto res = s.groupAnagrams(a);
    for(vector<string> v : res){
        for(string s : v) cout << s << ", ";
        cout << endl;
    }
        
    return 0;
}