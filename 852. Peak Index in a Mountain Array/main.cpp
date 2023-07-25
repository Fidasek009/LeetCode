#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while(i < arr.size()-1 && arr[i] < arr[i+1]) i++;
        return i;
    }
};

int main()
{
    vector<int> a = {0,10,5,2}; // 1
    Solution s = Solution();
    auto res = s.peakIndexInMountainArray(a);
    cout << res;
    return 0;
}