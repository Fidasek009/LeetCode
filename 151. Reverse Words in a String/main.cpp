#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string out;
        vector<string> words;
        // get the words
        for(int i = 0; i < s.length(); i++){
            string word = "";
            while(i < s.length() && s[i] != ' ') word.push_back(s[i++]);
            if(word != "") words.push_back(word);
        }
        // append the words in reverse
        while(words.size() > 0){
            out.append(words.back() + " ");
            words.pop_back();
        }
        // get rid of the tailing space
        out.pop_back();
        return out;
    }
};

int main()
{
    string a = "a good   example";
    Solution s = Solution();
    auto res = s.reverseWords(a);
    cout << res;
    return 0;
}