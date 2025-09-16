"""

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


STEPS

1 - Create a function that takes in 2 lists as its parameters
2 - Inside the function, create a 3rd list that will be the result of
    2 added lists

3 - swapped = True because for the while loop to keep looping, the
    condition must be true
4 - for swapped to be false, we are saying this is the last time we 
    loop because there's no need for swaps

5 - The for loop loops through the length of list3 minus 1 because we
    won't need to check the last element
6 - The if statement checks whether the current iteration is > the next
    iteration and if the statement is true, we're going to swap the
    current with the next

7 - Set swapped to True because we must check other elements in the list
    whether they need to be swapped or not
8 - Return list3


"""

class Solution:
    def listNode(self, list1, list2):

        list3 = list1 + list2
        swapped = True

        while swapped:
            swapped = False

            for i in range(len(list3)-1):
                if list3[i] > list3[i+1]:
                    temp = list3[i]
                    list3[i] = list3[i+1]
                    list3[i+1] = temp
                    swapped = True

        return list3
    
sol = Solution()

list1 = [1,2,3]
list2 = [1,3,4]

print(sol.listNode(list1,list2))
