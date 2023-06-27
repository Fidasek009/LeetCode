# Intuition
I used the basic pincipals of summing binary numbers.

# Approach
I managed to fit everything inside a single while loop. I have an iterator for every string. The `sum` is basically calculated like this: `a[i] + b[j] + remainder`. Then `out[k] = sum%2` and `remainder` is *true* if the `sum > 1`.

# Complexity
- Time complexity: ***O(n)***

- Space complexity: ***O(n)***

# Code
```
class Solution {
public:
    string addBinary(string a, string b) {
        // set the length of `out` to the longer string length +1 and fill it with '0'
        string out((a.length() > b.length()) ? a.length()+1 : b.length()+1, '0');
        int i = a.length()-1,   // iterator of string `a`
            j = b.length()-1,   // iterator of string `b`
            k = out.length()-1; // iterator of string `out`
        bool remainder = 0;     // remainder indicator

        while(k > -1){
            // bit in `a` + bit in `b` + `remainder`
            short sum = (i > -1 && a[i--] == '1') + (j > -1 && b[j--] == '1') + remainder;
            out[k--] = (sum%2 == 0) ? '0' : '1';
            remainder = (sum > 1);
        }

        // if the first character is '0' than strip it
        return (out[0] == '0') ? out.substr(1) : out;
    }
};
```