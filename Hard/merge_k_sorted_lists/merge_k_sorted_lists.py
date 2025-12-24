from typing import List
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeKLists(lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    if not lists:
        return None
    
    def mergeTwo(l1, l2):
        dummy = ListNode()
        current = dummy
        while l1 and l2:
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next
        
        if l1:
            current.next = l1
        if l2:
            current.next = l2
        return dummy.next
    
    merged = lists[0]
    for i in range(1, len(lists)):
        merged = mergeTwo(merged, lists[i])
    return merged

# Helper function to convert a list of ints to a linked list
def list_to_linked(lst):
    dummy = ListNode()
    curr = dummy
    for val in lst:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

# Helper function to print a linked list
def print_linked_list(node):
    vals = []
    while node:
        vals.append(node.val)
        node = node.next
    print(vals)

if __name__ == "__main__":
    input1 = [[1,4,5],[1,3,4],[2,6]]
    linked_lists = [list_to_linked(lst) for lst in input1]
    
    merged = mergeKLists(linked_lists)
    print("For input:", input1)
    print_linked_list(merged)  # Expected output: [1,1,2,3,4,4,5,6]

    # Testing empty input
    input2 = []
    print("For input:", input2)
    print_linked_list(mergeKLists(input2))  # Output: []

    # Testing list with empty lists
    input3 = [[]]
    print("For input:", input3)
    print_linked_list(mergeKLists(input3))