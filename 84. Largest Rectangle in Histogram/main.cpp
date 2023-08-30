#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        stack<pair<int, int>> fifo; // index, height

        for(int i = 0; i < heights.size(); i++){
            int start = i;
            // if current element is smaller than previos, calculate possible areas in stack
            while(!fifo.empty() && fifo.top().second > heights[i]){
                // check top element and pop it
                int index = fifo.top().first;
                int height = fifo.top().second;
                fifo.pop();

                // calculate area and check if it's bigger than max
                int area = height * (i - index);
                if(area > max) max = area;
                start = index;
            }

            // push the new height with the index from whitch it can be a rectangle
            fifo.push(pair(start, heights[i]));
        }

        // pop remaining elements and check their area
        while(!fifo.empty()){
            int area = fifo.top().second * (heights.size() - fifo.top().first);
            if(area > max) max = area;
            fifo.pop();
        }

        return max;
    }
};

int main()
{
    vector<int> a = {2,1,5,6,2,3};
    // vector<int> a = {3,5,5,2,5,5,6,6,4,4,1,1,2,5,5,6,6,4,1,3};
    Solution s = Solution();
    auto res = s.largestRectangleArea(a);
    cout << res;
    return 0;
}