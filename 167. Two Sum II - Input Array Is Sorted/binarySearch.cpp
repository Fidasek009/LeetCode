#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> arr, int l, int x){
        int r=arr.size()-1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            // Check if x is present at mid
            if (arr[m] == x) return m;
            // If x greater, ignore left half
            if (arr[m] < x) l = m + 1;
            // If x is smaller, ignore right half
            else r = m - 1;
        }
        // If we reach here, then element was not present
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> out(2);

        for(out[0] = 0; out[0] < numbers.size(); out[0]++){
            out[1] = binarySearch(numbers, out[0], target-numbers[out[0]]);
            if(out[1] != -1){
                out[1] += 1+(out[0] == out[1]);
                out[0]++;
                return out;
            }
        }

        return out;
    }
};

int main()
{
    vector<int> a = {2,7,11,15};
    int b = 9;

    Solution s = Solution();
    auto res = s.twoSum(a, b);
    cout << res[0] << ", " << res[1];
    return 0;
}