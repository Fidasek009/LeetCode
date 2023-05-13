#include <vector>
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        std::vector<ListNode *> v;
        // unpack the ListNode to vector of pointers
        while(head != nullptr){
            v.push_back(head);
            head = head->next;
        }

        return v[v.size()/2]; // return the middle pointer
    }
};

int main()
{
    std::vector<int> inp = {1,2,3,4,5};
    
    // construct ListNode from inp array
    ListNode* head = nullptr;  // Pointer to the head of the linked list

    for (int i = inp.size() - 1; i >= 0; i--) {
        ListNode* newNode = new ListNode(inp[i], head); // pointer newNode to a new instance of ListNode
        head = newNode;
    }

    Solution s = Solution();
    auto res = s.middleNode(head);
    std::cout << res->val;
    return 0;
}