#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> out(arr.size());
        int max = -1;

        for(int i = arr.size()-1; i > -1; i--){
            out[i] = max;
            if(arr[i] > max) max = arr[i];
        }

        return out;
    }
};

int main()
{
    vector a = {17,18,5,4,6,1};
    Solution s = Solution();
    auto res = s.replaceElements(a);
    for(int n : res) cout << n << ", ";
    return 0;
}