#include <vector>
#include <iostream>

// sometimes the simplest solution is the best soulution 😎
class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string s;

        // pop the front of both strings until at least one is empty
        while (word1.length() > 0 && word2.length() > 0){
            s.push_back(word1.front());
            word1 = word1.assign(word1.begin()+1, word1.end());
            s.push_back(word2.front());
            word2 = word2.assign(word2.begin()+1, word2.end());
        }

        // append the rest of the string to the output
        if(word1.length() > 0) s.append(word1.begin(), word1.end());
        else if(word2.length() > 0) s.append(word2.begin(), word2.end());

        return s;
    }
};


int main()
{
    std::string inp1 = "ab";
    std::string inp2 = "pqrs";
    Solution s = Solution();
    auto res = s.mergeAlternately(inp1, inp2);
    std::cout << res;
    return 0;
}