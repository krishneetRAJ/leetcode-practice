from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def deleteDuplicates(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head:
        return None

    current = head
    while current and current.next:
        if current.val == current.next.val:
            current.next = current.next.next 
        else:
            current = current.next 

    return head

# Example usage:
if __name__ == "__main__":
    print("Testing deleteDuplicates function:")
    # Create a sorted linked list: 1 -> 1 -> 2
    head = ListNode(1)
    head.next = ListNode(1)
    head.next.next = ListNode(2)

    result = deleteDuplicates(head)
    output = []
    while result:
        output.append(result.val)
        result = result.next
    print("For the input (1 -> 1 -> 2), the output is:", f"({' -> '.join(map(str, output))})")  # Output: (1->2)

    # Create another sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    head = ListNode(1)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(3)

    result = deleteDuplicates(head)
    output = []
    while result:
        output.append(result.val)
        result = result.next
    print("For the input (1 -> 1 -> 2 -> 3 -> 3), the output is:", f"({' -> '.join(map(str, output))})")  # Output: (1->2->3)

    