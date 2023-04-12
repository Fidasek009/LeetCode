#include <vector>
#include <iostream>


std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::vector<int> a;
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] + nums[j] == target){
                    a = {j, i};
                    return a;
                }
            }
        }
        return a;
}

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> answer = twoSum(nums, target);
    std::cout << answer[0] << ", " << answer[1];
}
