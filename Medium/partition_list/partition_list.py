from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def partition(head: Optional[ListNode], x: int) -> Optional[ListNode]:
    if not head:
        return None

    less_head = ListNode(0)
    greater_head = ListNode(0)

    less = less_head
    greater = greater_head

    while head:
        if head.val < x:
            less.next = head
            less = less.next
        else:
            greater.next = head
            greater = greater.next
        head = head.next

    greater.next = None
    less.next = greater_head.next

    return less_head.next

if __name__ == "__main__":
    print("Testing partition function:")
    # Create linked list 1 -> 4 -> 3 -> 2 -> 5 -> 2
    print("For the input linked list 1 -> 4 -> 3 -> 2 -> 5 -> 2 and x = 3, the output is:")
    head = ListNode(1)
    head.next = ListNode(4)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(2)
    head.next.next.next.next = ListNode(5)
    head.next.next.next.next.next = ListNode(2)

    x = 3
    new_head = partition(head, x)

    # Print the partitioned linked list
    current = new_head
    while current:
        if(current.next):
            print(current.val, end=", ")
        else:
            print(current.val, end="")
        current = current.next
    print()  # for newline after printing the list


    #Create linked list 2 -> 1
    print("")
    print("For the input linked list 2 -> 1 and x = 2, the output is:")
    head = ListNode(2)
    head.next = ListNode(1)
    x = 2
    new_head = partition(head, x)

    # Print the partitioned linked list
    current = new_head
    while current:
        if(current.next):
            print(current.val, end=", ")
        else:
            print(current.val, end="")
        current = current.next
    print()  # for newline after printing the list


