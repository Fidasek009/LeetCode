#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> &a, vector<int> &b){
        int i = 0, j = 0;
        vector<int> out;

        while(i < a.size() && j < b.size()) out.push_back((a[i] < b[j]) ? a[i++] : b[j++]);
        while(i < a.size()) out.push_back(a[i++]);
        while(j < b.size()) out.push_back(b[j++]);

        return out;
    }

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() < 2) return nums;

        int mid = nums.size()/2;

        vector<int> a = vector<int>(nums.begin(), nums.begin()+mid);
        vector<int> b = vector<int>(nums.begin()+mid, nums.end());
        a = sortArray(a);
        b = sortArray(b);

        return merge(a, b);
    }
};

int main()
{
    vector<int> a = {5,2,3,1};
    Solution s = Solution();
    auto res = s.sortArray(a);
    for(int x : res) cout << x << ", ";
    return 0;
}