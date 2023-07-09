#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> out;
        int min = list1.size() + list2.size();
        // create map from `list1`
        unordered_map<string, int> map;
        for(int i = 0; i < list1.size(); i++) map[list1[i]] = i;

        // match the strings from `list2`
        for(int i = 0; i < list2.size(); i++){
            if(map.find(list2[i]) != map.end()){
                int n = map[list2[i]] + i;
                if(n < min){
                    min = n;
                    out.clear();
                    out.push_back(list2[i]);
                }
                else if(n == min) out.push_back(list2[i]);
            }
        }

        return out;
    }
};

int main()
{
    // vector<string> a = {"Shogun","Tapioca Express","Burger King","KFC"};
    // vector<string> b = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> a = {"happy","sad","good"};
    vector<string> b = {"sad","happy","good"};
    Solution s = Solution();
    auto res = s.findRestaurant(a, b);
    for(string x : res) cout << x << ", ";
    return 0;
}