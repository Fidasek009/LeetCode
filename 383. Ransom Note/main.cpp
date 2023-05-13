#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // construct a map of char count in magazine
        std::unordered_map<char, int> chars;
        for(char c : magazine) chars[c]++;
        
        // go through ransomNote subtracting char counts
        for(char c : ransomNote){
            if(chars[c] > 0) chars[c]--;
            else return false;
        }

        return true;
    }
};

int main()
{
    std::string ran = "aba";
    std::string mag = "baa";
    Solution s = Solution();
    auto res = s.canConstruct(ran, mag);
    std::cout << res;
    return 0;
}