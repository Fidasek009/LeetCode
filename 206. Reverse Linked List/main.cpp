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
    ListNode* reverseList(ListNode* head) {
        // last element
        if(head == nullptr || head->next == nullptr) return head;
        
        // call recursively
        ListNode* x = reverseList(head->next);

        // swap pointer direction
        head->next->next = head;
        head->next = nullptr;

        return x;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    auto res = s.reverseList(ln);
    
    while (res != nullptr){
        cout << res->val << ", ";
        res = res->next;
    }

    return 0;
}