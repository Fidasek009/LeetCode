#include <iostream>


using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int sl = s.length();
        const int pl = p.length();

        // regex is complete
        if(sl == 0 && pl == 0)
            return true;

        // either one or the other is empty
        if(sl > 0 && pl == 0 || sl == 0 && pl > 0) return false;

        const bool dot = p[0] == '.';
        const bool star = (pl > 1) ? p[1] == '*' : false;

        // regex has no special chars
        if(!dot && !star){
            if(s[0] == p[0])
                return isMatch(s.substr(1, sl), p.substr(1, pl));
            else
                return false;
        }

        //regex only has dot
        if(dot && !star)
            return isMatch(s.substr(1, sl), p.substr(1, pl));


        // dedpue pattern (eg. a*a*a* OR .*.*.*)
        int offset = 2;
        while(offset < pl && (p[offset] == p[0] || p[offset] == '*')) offset++;

        // regex only has star
        if(!dot && star){
            // 1st character doesnt match → strip pattern
            if(s[0] != p[0]) return isMatch(s, p.substr(2, pl));

            // search pattern
            for(int i = 1; i < sl; i++) // 0 is already checked
                if(s[i] != p[0])
                    return isMatch(s.substr(i, sl), p.substr(offset, pl));

            // end of `s` → check if pattern is empty
            return pl-offset == 0;
        }

        // dot + star
        if(dot && star){
            // pattern ends with `.*`
            if(pl == 2) return true;

            for(int i = 0; i < sl; i++)
                if(s[i] == p[3])
                    return isMatch(s.substr(i, sl), p.substr(offset, pl));
        }

        return false;
    }
};

int main()
{
    string str = "aaa";
    string reg = "ab*a*c*a";    // #NeverGiveUp (just postpone the solution 😉)
    Solution s = Solution();
    auto res = s.isMatch(str, reg);
    cout << res;
    return 0;
}

/*
TESTS:
aa
a*
> true  ✅

aaaaaaaaaaaaaaaaaaa
a*a*a*a*a*a*a*a*a*b
> false ✅

ab
.*c
> false ✅

aaa
ab*a*c*a    ← this is where I realised this problem requires a different approach and my skills are not yet on that level therefore I give up for now 🙃
> true  ⛔
*/