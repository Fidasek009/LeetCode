#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write=0, read=1;

        while (read < nums.size()){
            // find closest occurance of 0
            while(write < nums.size()-1 && nums[write] != 0) write++;

            // read needs to be higher than write
            if(write+1 > read) read = write+1;

            // did I reach end
            if(read == nums.size()) return;

            // find closest occurrance of a !0 element
            while(read < nums.size()-1 && nums[read] == 0) read++;

            // swap elements
            nums[write++] = nums[read];
            nums[read++] = 0;
        }
    }
};

int main()
{   
    
    vector a = {0,1,0,3,12};
    // vector a = {1,2};
    // vector a = {1,0,1};
    // vector a = {0,0};
    // vector a = {4,2,4,0,0,3,0,5,1,0};
    Solution s = Solution();
    s.moveZeroes(a);
    for(int n : a) cout << n << ", ";
    return 0;
}