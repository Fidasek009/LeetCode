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
    ListNode* removeElements(ListNode* head, int val) {
        // get rid of leading values
        while(head && head->val == val) head = head->next;

        ListNode *it=head;
        while(it && it->next){
            if(it->next->val == val) it->next = it->next->next;
            else it = it->next;
        }

        return head;
    }
};

int main()
{
    // vector<int> a = {1,2,6,3,4,5,6};
    // int b = 6;
    // vector<int> a = {};
    // int b = 1;
    // vector<int> a = {7,7,7,7};
    // int b = 7;
    vector<int> a = {1,2,2,1};
    int b = 2;


    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    ListNode* res = s.removeElements(ln, b);
    while(res){
        cout << res->val << ", ";
        res = res->next;
    }
    return 0;
}