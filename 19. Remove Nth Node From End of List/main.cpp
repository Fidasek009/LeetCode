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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;

        // construct an array
        while(head){
            arr.push_back(head);
            head = head->next;
        }

        int s = arr.size();
        if(s == 1) return nullptr;
        if(s == n) return arr[1];

        // rewrite pointer
        arr[s-n-1]->next = (n > 1) ? arr[s-n+1] : nullptr;
        // delete element
        delete arr[s-n];

        return arr[0];
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);

    Solution s = Solution();
    ListNode* res = s.removeNthFromEnd(ln, 5);
    while(res){
        cout << res->val << ", ";
        res = res->next;
    }
    return 0;
}