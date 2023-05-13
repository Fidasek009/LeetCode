from typing import Optional



class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next



class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow: ListNode = head
        fast: ListNode = head
        while fast:
            fast = fast.next
            if fast:
                fast = fast.next
                slow = slow.next
        
        return slow



def main():
    inp = [1,2,3,4,5,6]
    head = None
    for n in reversed(inp): head = ListNode(n, head)

    s = Solution()
    print(s.middleNode(head).val)


if __name__ == "__main__":
    main()