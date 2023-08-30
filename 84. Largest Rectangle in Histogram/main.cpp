#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int len;
    int max = 0;
    vector<int> histogram;

    void calc(int left, int right, int min){
        if(right > len) return;

        // check if new right element is smaller than current min
        if(histogram[right-1] < min) min = histogram[right-1];

        // calculate rectangle area and check with max
        int area = min * (right-left);
        if(area > max) max = area;

        // recursion 1: increase only right border
        calc(left, right+1, min);

        // check if left can be increased
        if(left+1 == right) return;

        // find new min if the current left is the smallest
        if(histogram[left++] == min) {
            min = histogram[left];
            for(int i = left; i < right; i++)
                if(histogram[i] < min)
                    min = histogram[i];
        }

        // recursion 2: increase only left border
        calc(left, right, min);

        // recursion 3: increase both borders
        calc(left, right+1, min);
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        len = heights.size();
        histogram = heights;

        // empty vector
        if(len == 0) return 0;

        calc(19, 20, histogram[0]);
        return max;
    }
};

int main()
{
    // vector<int> a = {2,1,5,6,2,3};
    vector<int> a = {3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
    Solution s = Solution();
    auto res = s.largestRectangleArea(a);
    cout << res;
    return 0;
}