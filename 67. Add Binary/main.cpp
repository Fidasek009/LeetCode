#include <iostream>
#include <math.h>

using namespace std;

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

int main()
{

    string a = "11";
    string b = "1";

    // string a = "1111";
    // string b = "1111";

    // string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    // string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    
    Solution s = Solution();
    auto res = s.addBinary(a, b);
    cout << res;
    return 0;
}