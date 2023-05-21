#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        
    }
};

int main()
{
    auto inp = 0;

    vector<int> a = {1,2,3,4,5};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);
    
    Solution s = Solution();
    auto res = s.detectCycle(inp);
    cout << res;
    return 0;
}