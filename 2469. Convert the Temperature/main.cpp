#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};

int main()
{
    double a = 35;
    Solution s = Solution();
    auto res = s.convertTemperature(a);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}