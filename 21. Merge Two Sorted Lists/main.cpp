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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // itarator - points to last sorted element
        ListNode* it = new ListNode(0, nullptr);
        ListNode* res = it;

        while(list1 != nullptr && list2 != nullptr){
            // pointer to the smaller element
            ListNode* smaller;
            
            if(list1->val < list2->val){
                smaller = list1;
                list1 = list1->next;
            }
            else{
                smaller = list2;
                list2 = list2->next;
            }

            // set and move iterator
            it->next = smaller;
            it = it->next;
        }
        
        // fill the rest of items
        if(list1 != nullptr) it->next = list1;
        else if(list2 != nullptr) it->next = list2;

        return res->next;
    }
};

int main()
{
    const int a[] = {1,2,4};
    const int b[] = {1,3,4};

    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    for (int i = sizeof(a)/sizeof(a[0]) - 1; i >= 0; i--) {
        ListNode* newNode = new ListNode(a[i], l1);
        l1 = newNode;
    }

    for (int i = sizeof(b)/sizeof(b[0]) - 1; i >= 0; i--) {
        ListNode* newNode = new ListNode(b[i], l2);
        l2 = newNode;
    }


    Solution s = Solution();
    auto res = s.mergeTwoLists(l1,l2);

    while (res != nullptr){
        cout << res->val << ", ";
        res = res->next;
    }
    
    return 0;
}