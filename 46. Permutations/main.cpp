#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> p;

    void gen(vector<int> seq, int n){
        if(n == seq.size()) return p.push_back(seq);

        for(int i = n; i < seq.size(); i++){
            // swap elements
            int tmp = seq[i];
            seq[i] = seq[n];
            seq[n] = tmp;
            
            gen(seq, n+1);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        gen(nums, 0);
        return p;
    }
};

int main()
{
    vector<int> a = {1,2,3};
    // vector<int> a = {0,1};
    Solution s = Solution();
    auto res = s.permute(a);
    for(vector<int> v : res){
        for(int x : v) cout << x << ", ";
        cout << endl;
    }
    return 0;
}