#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> out;
        int i=0, j=0;
        while(i < nums1.size() && j < nums2.size()){
            while(i < nums1.size() && nums1[i] < nums2[j]) i++;
            while(j < nums2.size() && nums2[j] < nums1[i]) j++;
            if(nums1[i] == nums2[j]) out.push_back(nums1[i]);
            i++;
            j++;
        }

        return out;
    }
};

int main()
{
    vector<int> a = {1,2};
    vector<int> b = {1,1};
    Solution s = Solution();
    auto res = s.intersect(a, b);
    for(int x : res) cout << x << ", ";
    return 0;
}