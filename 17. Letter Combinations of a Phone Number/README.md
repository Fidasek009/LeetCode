# Intuition
At first glance I saw the potential of using backtracking to solve this problem.

# Approach
To store characters I use a `vector<string> chars`. To convert a character in `digits` to correspond with `chars` I jsut subtract 50 (the ASCII value of 2). For backtracking i have a recursive function `gen()`. You really only need to send the current sequence and the current position in `digits`.

# Complexity
- Time complexity: ***O(3^n)***
- Space complexity: ***O(3^n)***

# Code
```
class Solution {
private:
    vector<string> chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> out;
    string d;

    void gen(string seq, int n){
        if(n == d.length()) return out.push_back(seq);

        for(char x : chars[d[n]-50]){
            string newSeq = seq;
            newSeq.push_back(x);
            gen(newSeq, n+1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        d = digits;
        gen("", 0);
        return out;
    }
};
```