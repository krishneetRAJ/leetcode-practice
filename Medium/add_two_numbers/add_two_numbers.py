from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    dummy_head = ListNode(0)
    current = dummy_head
    carry = 0

    while l1 or l2 or carry:
        if l1:
            val1 = l1.val
        else:
            val1 = 0    
        if l2:
            val2 = l2.val
        else:
            val2 = 0

        total = val1 + val2 + carry
        carry = total // 10
        current.next = ListNode(total % 10)
        current = current.next

        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next

    return dummy_head.next


if __name__ == "__main__":
    print("Testing addTwoNumbers function:")
    print("First solution: Inputs are [2 -> 4 -> 3] and [5 -> 6 -> 4]")
    # Create first linked list: 2 -> 4 -> 3
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    # Create second linked list: 5 -> 6 -> 4
    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    result = addTwoNumbers(l1, l2)
    output = []
    while result:
        output.append(result.val)
        result = result.next
    print("For the input (2 -> 4 -> 3) + (5 -> 6 -> 4), the output is:", f"({' -> '.join(map(str, output))})")  # Output: (7->0->8)

    print("")
    print("Second solution: Inputs are [0] and [0]")
    # Create first linked list: 0
    l1 = ListNode(0)    
    # Create second linked list: 0
    l2 = ListNode(0)

    result = addTwoNumbers(l1, l2)
    output = []
    while result:
        output.append(result.val)
        result = result.next
    print("For the input (0) + (0), the output is:", f"({' -> '.join(map(str, output))})")  # Output: (0)

    print("")
    print("Third solution: Inputs are [9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9] and [9 -> 9 -> 9 -> 9]")
    # Create first linked list: 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
    l1 = ListNode(9)
    l1.next = ListNode(9)
    l1.next.next = ListNode(9)
    l1.next.next.next = ListNode(9)
    l1.next.next.next.next = ListNode(9)
    l1.next.next.next.next.next = ListNode(9)
    l1.next.next.next.next.next.next = ListNode(9)
    l1.next.next.next.next.next.next.next = ListNode(9)

    # Create second linked list: 9 -> 9 -> 9 -> 9
    l2 = ListNode(9)
    l2.next = ListNode(9)
    l2.next.next = ListNode(9)
    l2.next.next.next = ListNode(9)

    result = addTwoNumbers(l1, l2)
    output = []
    while result:
        output.append(result.val)
        result = result.next
    print("For the input (9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9) + (9 -> 9 -> 9 -> 9), the output is:", f"({' -> '.join(map(str, output))})")  # Output: (8->9->9->9->0->0->0)