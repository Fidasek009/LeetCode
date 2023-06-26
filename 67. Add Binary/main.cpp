#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string out((a.length() > b.length()) ? a.length()+1 : b.length()+1, '0');
        int out1 = 0;

        // add `a` to `out1`
        for(int i =  a.length()-1; i > -1; i--) if(a[i] == '1') out1 += pow(2, a.length()-1-i);
        // add `b` to `out1`
        for(int i =  b.length()-1; i > -1; i--) if(b[i] == '1') out1 += pow(2, b.length()-1-i);

        for(int i = 0; out1 > 0; i++){
            int n = pow(2, out.length()-1-i);
            if(out1+1 > n) {
                out[i] = '1';
                out1 -= n;
            }
        }

        return (out[0] == '1') ? out : out.substr(1);
    }
};

int main()
{
    string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    Solution s = Solution();
    auto res = s.addBinary(a, b);
    cout << res;
    return 0;
}