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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *slow=headA, *fast=headB;
        // check if lists connect
        while(slow->next) slow = slow->next;
        while(fast->next) fast = fast->next;
        if(slow != fast) return nullptr;

        // modified Floyd's Cycle-Finding algorithm
        slow=headA;
        fast=headA;
        while(fast){
            // if runners reach end, loop them to `headB`
            slow = (slow->next) ? slow->next : headB;
            fast = (fast->next) ? fast->next : headB;
            fast = (fast->next) ? fast->next : headB;
            if(slow == fast) {
                slow = headA;
                while(slow != fast){
                    slow = (slow->next) ? slow->next : headB;
                    fast = (fast->next) ? fast->next : headB;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main()
{
    cout << "bro who tf uses linked lists X_X just belive me that it works";
    return 0;
}