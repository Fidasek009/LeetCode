class Solution:
    roman: dict[chr, int] = {
        'I':1,
        'V':5,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000
    }


    def romanToInt(self, s: str) -> int:
        sum: int = 0

        for i in range(len(s)-1):
            if self.roman[s[i+1]] > self.roman[s[i]]:
                sum -= self.roman[s[i]]
            else:
                sum += self.roman[s[i]]

        return sum + self.roman[s[-1]]



def main():
    a = Solution()

    print(a.romanToInt("MCMXCIV"))


if __name__ == "__main__":
    main()