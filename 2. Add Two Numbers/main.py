from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val: int=0, next: 'ListNode'=None):
        self.val: int = val
        self.next: ListNode = next
    
    def __str__(self) -> str:
        ln = self
        s = ""
        while ln is not None:
            s += str(ln.val)
            ln = ln.next
        return s[::-1]


# ======================SOLUTION======================
def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    result = []
    final: ListNode = None
    remainder = False

    while l1 is not None or l2 is not None:
        # add the two numbers together
        if l1 is not None and l2 is not None:
            sum = l1.val + l2.val
            l1 = l1.next
            l2 = l2.next
        elif l1 is not None:
            sum = l1.val
            l1 = l1.next
        else:
            sum = l2.val
            l2 = l2.next
        sum += remainder # add the remainder of last sum

        # determine if there should be a remainder
        if sum > 9:
            remainder = True
            sum -= 10
        else: remainder = False

        result.append(sum)
    
    # extend the result if there is still a remainder
    if remainder: result.append(1)
    
    # assemble ListNode by reversing result array
    for i in reversed(range(len(result))):
        final = ListNode(result[i], final)
    
    return final
# ============================================


# Create the ListNodes according to the task
num1 = "342"
num2 = "465"
ln1: ListNode = None
ln2: ListNode = None
for x in num1: ln1 = ListNode(int(x), ln1)
for x in num2: ln2 = ListNode(int(x), ln2)

output: ListNode = addTwoNumbers(ln1, ln2)

print(output)