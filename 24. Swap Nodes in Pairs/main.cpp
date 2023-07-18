#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *next = nullptr;
        // call recursion
        if(head && head->next) next = swapPairs(head->next->next);
        else return head;

        // swap nodes
        ListNode *newHead = head->next;
        newHead->next = head;
        head->next = next;

        return newHead;
    }
};


int main()
{
    // vector<int> a = {1,2,3,4};
    vector<int> a = {};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    ListNode *res = s.swapPairs(ln);
    while(res){
        cout << res->val << ", ";
        res = res->next;
    }
    return 0;
}