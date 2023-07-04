#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        stack<int> lifo;
        ListNode *fast=head;

        // find half point and put 1st half on stack
        while(fast && fast->next){
            lifo.push(head->val);
            head = head->next;
            fast = fast->next->next;
        }

        // list is odd
        if(fast) head = head->next;

        // pop items from stack if they match
        while(head && lifo.top() == head->val){
            head = head->next;
            lifo.pop();
        }

        return lifo.empty();
    }
};

int main()
{
    vector<int> a = {1,2,3,2,1};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    auto res = s.isPalindrome(ln);
    cout << res;
    return 0;
}