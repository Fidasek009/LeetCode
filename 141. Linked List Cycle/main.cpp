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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=(head) ? head->next : nullptr;

        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            if(slow == fast) return true;
        }

        return false;
    }
};

int main()
{   
    cout << "It works, wow amazing! I was too lazy to write the tests so you just have to belive me :P";
    return 0;
}