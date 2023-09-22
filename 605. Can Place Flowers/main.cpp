#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        // edge case
        if(len == 1) return flowerbed[0] == 0 || n == 0;

        // check the array edges
        if(len > 1){
            if(flowerbed[0] == 0 && flowerbed[1] == 0){
                flowerbed[0] = 1;
                n--;
            }
            if(flowerbed[len-1] == 0 && flowerbed[len-2] == 0){
                flowerbed[len-1] = 1;
                n--;
            }
        }

        // check the inside of the array
        for(int i = 2; i < len-2; i++){
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                i++;
                n--;
            }
            if(n == 0) return true;
        }

        return n < 1;
    }
};

int main()
{
    vector<int> a = {1,0,0,0,1};
    int n = 1;
    Solution s = Solution();
    auto res = s.canPlaceFlowers(a, n);
    cout << res;
    return 0;
}