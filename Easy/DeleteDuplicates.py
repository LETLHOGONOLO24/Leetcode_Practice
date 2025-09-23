"""

Given the head of a sorted linked list, delete all duplicates such
that each element appears only once. Return the linked list sorted
as well.

Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.



STEPS


1 - class ListNode: → defines a class called ListNode, which
    represents a node in a linked list.
2 - def __init__(self, val=0, next=None): → the constructor
    method that runs when you create a new node.

    val → stores the value of the node (default is 0).
    next → stores a reference (pointer) to the next node
    in the list (default is None if it's the last node).

3 - self.val = val → assigns the value to this node. self.next = next
    → assigns the reference to the next node

4 - current → a pointer variable used to traverse the list. Initially,
    current points to the head of the list. You never change head,
    because you need it to return the start of the modified list at the end.
    Linked list concept: You traverse the list node by node using a variable
    like current, following the .next pointers.

5 - while current and current.next: → continue looping as long as: current is
    not None (we haven't reached the end of the list), AND current.next is not
    None (there is a next node to compare with). We check both to avoid AttributeError
    when doing current.next.val.

6 - current.val == current.next.val → checks if current node and next node have the same
    value. current.next = current.next.next → skip the duplicate node:

    Instead of pointing to the duplicate node, current.next now points to the node after
    the duplicate. The duplicate node is effectively removed from the list.

7 - else: current = current.next -> If current node's value ≠ next node's value, we move
    the walker forward. current now points to the next unique node. This continues until
    the end of the list.

8 - The head pointer still points to the start of the linked list. After duplicates are
    removed, we return this pointer so the caller can access the updated list.

9 - Converting a python list to a linked list
    if not values: return None → handles empty list case.
    head = ListNode(values[0]) → creates the first node.

    current = head → pointer to build the rest of the list.
    Loop through values[1:]:
        Create a new node for each value.
        Link it to the current node using current.next.
        Move current forward.

    Finally, return head → first node of the linked list.
10 - Convert a linked list back to a python list

    Create an empty list result to store node values.
    current = head → start at the first node.
    
    Loop while current is not None:
        Append current.val to result.
        Move to the next node using current = current.next.
    Return result → Python list representation of the linked list.



"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head):

        current = head

        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next 

        return head
    
def list_to_linkedlist(values):
        if not values:
            return None
        
        head = ListNode(values[0])
        current = head

        for v in values[1:]: # Start at the 2nd element
            current.next = ListNode(v)
            current = current.next

        return head
    
def linkedlist_to_list(head):
    result = []
    current = head

    while current:
        result.append(current.val)
        current = current.next

    return result
    
sol = Solution()

head =list_to_linkedlist( [1,1,2,3])
result = sol.deleteDuplicates(head)
print(linkedlist_to_list(result))