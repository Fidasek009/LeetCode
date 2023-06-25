# Intuition
I immediately realised there is no need to calculate the 2nd half of the row as it is only the 1st half mirrored.

# Approach
It is sort of self explanatory. I just had to figure out the odd and even rows.

# Complexity
- Time complexity: ***O(n^2)***
- Space complexity: ***O(n^2)***

# Code
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out(numRows);

        for(int i = 0; i < numRows; i++){
            out[i] = {1};

            // generate first half of row
            for(int j = 1; j < i/2+1; j++) out[i].push_back(out[i-1][j] + out[i-1][j-1]);

            // append the flipped half
            out[i].insert(out[i].end(), out[i].rbegin()+(i%2==0), out[i].rend());
        }

        return out;
    }
};
```