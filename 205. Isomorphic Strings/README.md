# Intuition
I immediately realised to use a hash map to map the characters in string `s` to characters in string `t`

# Approach
I passed the basic tests within 5 minutes of coding. However an issue arised after getting `s="badc"`, `t="baba"`. The problem was that `s` maps to `t`, but not in reverse. I didn't want to use a second map, although it would be probably faster🤷. The trick i found was to also check if the first ocurrance of character is on my current position, so i came up with this: `t.find(t[i]) == i`.

# Complexity
- Time complexity: **O(n)**
- Space complexity: **O(n)**

# Code
```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;

        for(int i = 0; i < s.size(); i++){
            // char not in map AND it is its 1st ocurrance
            if(map.find(s[i]) == map.end() && t.find(t[i]) == i) map[s[i]] = t[i];
            // mapped characters dont correspond
            else if(map[s[i]] != t[i]) return false;
        }

        return true;
    }
};
```