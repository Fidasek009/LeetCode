class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for a in ransomNote:
            if a in magazine:
                i = magazine.find(a)
                magazine = magazine[:i] + magazine[i+1:]
                
            else: return False

        return True



def main():
    s = Solution()
    ran = "aa"
    mag = "ab"
    print(s.canConstruct(ran, mag))


if __name__ == "__main__":
    main()