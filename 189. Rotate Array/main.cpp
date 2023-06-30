#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> out;
        // get an actual needed `k`
        if(k > nums.size()) k %= nums.size();
        // get the back `k` elements
        out.insert(out.begin(), nums.end()-k, nums.end());
        // get the rest of elements
        out.insert(out.end(), nums.begin(), nums.end()-k);

        nums = out;
    }
};

int main()
{
    // vector<int> a = {1,2,3,4,5,6,7};
    // int b = 3;
    vector<int> a = {-1};
    int b = 2;
    Solution s = Solution();
    s.rotate(a, b);
    for(int x : a) cout << x << ", ";
    return 0;
}