#include <vector>
#include <iostream>
#include <unordered_set>

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
        unordered_set<ListNode*> visited;

        while(head){
            if(visited.find(head) != visited.end()) return head;
            visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5};
    ListNode* ln = nullptr;
    for(int i = a.size()-1; i >= 0; i--) ln = new ListNode(a[i], ln);
    
    Solution s = Solution();
    auto res = s.detectCycle(ln);
    cout << res;
    return 0;
}