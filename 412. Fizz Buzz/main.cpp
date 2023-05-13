#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> x = std::vector<std::string>();
        for(int i = 1; i < n+1; i++){
            bool three = i % 3 == 0;
            bool five = i % 5 == 0;

            if(three && five) x.push_back("FizzBuzz");
            else if(three) x.push_back("Fizz");
            else if(five) x.push_back("Buzz");
            else x.push_back(std::to_string(i));
            
        }
        return x;
    }
};


int main()
{
    auto inp = 100;
    Solution s = Solution();
    auto res = s.fizzBuzz(inp);

    for(auto& x : res) std::cout << x << ", ";

    return 0;
}
