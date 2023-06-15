#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums;

        for(int i = 0; i < arr.size(); i++){
            if(nums.find(arr[i]*2) != nums.end()) return true;
            if(arr[i] % 2 == 0 && nums.find(arr[i]/2) != nums.end()) return true;
            nums.insert(arr[i]);
        }

        return false;
    }
};

int main()
{
    //vector a = {10,2,5,3};
    //vector a = {3,1,7,11};
    //vector a = {-10,12,-20,-8,15};
    vector a = {-2,0,10,-19,4,6,-8};
    Solution s = Solution();
    auto res = s.checkIfExist(a);
    cout << res;
    return 0;
}