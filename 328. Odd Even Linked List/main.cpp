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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *odd = head,
            *evenHead = head->next,
            *even = evenHead;
        
        while(odd->next && even->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

int main()
{
    vector<int> a = {2,1,3,5,6,4};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    auto res = s.oddEvenList(ln);

    while (res != nullptr){
        cout << res->val << ", ";
        res = res->next;
    }
    return 0;
}