#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m, j=0; j < n; i++, j++) nums1[i] = nums2[j];
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0}, b = {2, 5, 6};
    int m = 3, n = 3;

    Solution s = Solution();
    s.merge(a,m,b,n);
    for(int x : a) cout << x << ", ";
    return 0;
}