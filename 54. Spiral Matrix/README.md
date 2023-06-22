# Intuition
I decided to take advantage of the constraint `-100 <= matrix[i][j] <= 100` so to mark visited elements I simply set it to **128** (can be anything higher than 100)

# Approach
I went with a while loop aproach ending when `out.size()` reaches the number of elements in `matrix`. I have 4 nested while loops each going in a different direction.

# Complexity
- Time complexity: ***O(n)***

- Space complexity: ***O(n)***

# Code
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int m = matrix.size()-1,                      // height
            n = matrix[0].size()-1,                   // width
            size = matrix.size()*matrix[0].size(),    // total element count
            y = 0,                                    // starting y position
            x = -1;                                   // starting x position
            
            

        while(out.size() < size){
            // →
            while(x < n && matrix[y][x+1] < 128) {
                out.push_back(matrix[y][++x]);
                matrix[y][x] = 128;
            }
            // ↓
            while(y < m && matrix[y+1][x] < 128) {
                out.push_back(matrix[++y][x]);
                matrix[y][x] = 128;
            }
            // ←
            while(x > 0 && matrix[y][x-1] < 128) {
                out.push_back(matrix[y][--x]);
                matrix[y][x] = 128;
            }
            // ↑
            while(y > 0 && matrix[y-1][x] < 128) {
                out.push_back(matrix[--y][x]);
                matrix[y][x] = 128;
            }
        }

        return out;
    }
};
```