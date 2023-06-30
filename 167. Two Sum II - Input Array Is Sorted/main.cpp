#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target) return {l+1, r+1};
            if(sum < target) l++;
            else r--;
        }

        return {0, 0};
    }
};

int main()
{
    // vector<int> a = {2,7,11,15}; // 0,1
    // int b = 9;
    // vector<int> a = {1,2,3,4,4,9,56,90}; // 3,4
    // int b = 8;
    vector<int> a = {3,2,4}; // 1,2
    int b = 6;
    // vector<int> a = {0,0,3,4};
    // int b = 0;
    // vector<int> a = {5,25,75};
    // int b = 100;


    Solution s = Solution();
    // auto res = s.binarySearch(a, b);
    // cout << res;
    auto res = s.twoSum(a, b);
    cout << res[0] << ", " << res[1];
    return 0;
}