#include <vector>
#include <iostream>

class Solution {
public:
    std::string gcdOfStrings(const std::string str1, const std::string str2) {
        std::string output = "";
        std::string divisor;
        const std::string *longer;
        const std::string *shorter;
        

        if (str1.length() > str2.length()){
            longer = &str1;
            shorter = &str2;
        }
        else {
            shorter = &str1;
            longer = &str2;
        }


        for(int i = 0; i < shorter->length(); i++){
            if(str1[i] == str2[i]){
                divisor.push_back((*longer)[i]);

                bool gut = true;
                int j = i+1;
                int k = 0;
                int l = 0;
                while(j < longer->length()){
                    if((*longer)[j++] != divisor[k] || (*shorter)[l++] != divisor[k]) {
                        gut = false;
                        break;
                    }
                    k++;
                    if(k == divisor.length()) k = 0;
                    if(l == shorter->length()) l = 0;
                }

                if(gut && str1.length() % divisor.length()  == 0 &&  str2.length() % divisor.length() == 0) output = divisor;
            }
        }
        return output;
    }
};

int main()
{
    std::string inp1 = "CXTXNCXTXNCXTXNCXTXNCXTXN";
    std::string inp2 = "CXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXNCXTXN";
    Solution s = Solution();
    auto res = s.gcdOfStrings(inp1, inp2);
    std::cout << res;
    return 0;
}