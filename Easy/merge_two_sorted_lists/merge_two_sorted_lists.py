from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode()
    curr = dummy

    while list1 and list2:
        if list1.val < list2.val:
            curr.next = list1
            list1 = list1.next
        else:
            curr.next = list2
            list2 = list2.next
        curr = curr.next

    if list1:
        curr.next = list1
    else:
        curr.next = list2

    return dummy.next

#Example usage:
if __name__ == "__main__":
    print("Testing mergeTwoLists function:")
    print("Merging two sorted linked lists: [1 -> 2 -> 4] and [1 -> 3 -> 4]")
    # Creating first sorted linked list: 1 -> 2 -> 4
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(4)
    print("First sorted linked list:")
    curr = list1
    while curr:
        print(curr.val, end=" -> ")
        curr = curr.next
    print("None")

    # Creating second sorted linked list: 1 -> 3 -> 4
    list2 = ListNode(1)
    list2.next = ListNode(3)
    list2.next.next = ListNode(4)
    print("Second sorted linked list:")
    curr = list2
    while curr:
        print(curr.val, end=" -> ")
        curr = curr.next
    print("None")

    # Merging the two sorted linked lists
    merged_list = mergeTwoLists(None, list1, list2)

    # Printing the merged linked list
    print("Merged sorted linked list:")
    while merged_list:
        print(merged_list.val, end=" -> ")
        merged_list = merged_list.next
    print("None")  # Indicating the end of the linked list


    #Second test case
    print("\nMerging two sorted linked lists: [] and []")
    # Creating first sorted linked list: []
    list1 = None
    print("First sorted linked list: None")
    # Creating second sorted linked list: []
    list2 = None
    print("Second sorted linked list: None")

    # Merging the two sorted linked lists
    merged_list = mergeTwoLists(None, list1, list2)

    # Printing the merged linked list
    print("Merged sorted linked list:")
    if not merged_list:
        print("None")

    #Third test case
    print("\nMerging two sorted linked lists: [] and [0]")
    # Creating first sorted linked list: []
    list1 = None
    print("First sorted linked list: None")
    # Creating second sorted linked list: [0]
    list2 = ListNode(0)
    print("Second sorted linked list:")
    curr = list2
    while curr:
        print(curr.val, end=" -> ")
        curr = curr.next
    print("None")
    