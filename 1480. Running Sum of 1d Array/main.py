class Solution(object):
    def runningSum(self, nums: list[int]) -> list[int]:
        out = []
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            out.append(sum)
        return out



def main():
    inp = [1,2,3,4]
    print(Solution.runningSum(Solution(), inp))


if __name__ == "__main__":
    main()