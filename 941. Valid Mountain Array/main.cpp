#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;

        int i = 1;

        //go up to peak
        while(i<arr.size()-1 && arr[i-1] < arr[i]+1) i++;
        
        // peak needs to be higher than arr[0] and it cant be at the end of arr
        if(arr[0]+1 > arr[i] || i == arr.size()) return false;

        //go down from peak
        while(i < arr.size() && arr[i-1] > arr[i]) i++;

        return i == arr.size();
    }
};

int main()
{
    //vector a = {0,3,2,1}; // true
    //vector a = {2,1};     // false
    vector a = {3,5,5};     // false
    Solution s = Solution();
    auto res = s.validMountainArray(a);
    cout << res;
    return 0;
}