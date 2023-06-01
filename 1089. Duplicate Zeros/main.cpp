#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0, j=0;
        vector<int> copy(arr.begin(), arr.end());

        while(j < arr.size()){
            arr[j] = copy[i++];

            if(arr[j] == 0 && j+1 < arr.size()){
                arr[j+1] = 0;
                j++;
            }
            j++;
        }
    }
};

int main()
{
    //vector a = {0};
    vector a = {1,0,2,3,0,4,5,0}; // [1,0,0,2,3,0,0,4]
    //vector a = {0,0,0,0,0,0,0};
    Solution s = Solution();
    s.duplicateZeros(a);
    for(int n : a) cout << n << ", ";
    return 0;
}