#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> vectorize(int n){
        vector<int> out;

        while(n > 0){
            out.push_back(n % 10);
            n /= 10;
        }

        return out;
    }

    bool isHappy(int n) {
        int sum = n;
        unordered_set<int> seen({n});

        while(sum != 1){
            vector<int> digits(vectorize(sum));
            // calculate `sum`
            sum = 0;
            for(int x : digits) sum += x*x;
            // check if already seen
            if(seen.find(sum) == seen.end()) seen.insert(sum);
            else return false;
        }

        return true;
    }
};

int main()
{
    int a = 2;
    Solution s = Solution();
    auto res = s.isHappy(a);
    cout << res;
    return 0;
}