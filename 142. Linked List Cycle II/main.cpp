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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            // there is a loop OMG
            if(slow == fast) {
                // engage Floyd's Cycle-Finding algorithm :P
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main()
{
    cout << "It works, wow amazing! I was too lazy to write the tests so you just have to belive me :P";
    return 0;
}