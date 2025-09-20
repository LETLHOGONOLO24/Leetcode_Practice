"""

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104


STEPS

Start with the entire sorted array
Find the middle element

Compare middle element with target:
If equal → Found it!
If target is smaller → Search left half

If target is larger → Search right half
Repeat until found or array is empty


1 -  This problem required us to use binary search because of 0(log n)
    runtime complexity
2 - We declare a function searchInsert that takes a nums array and int
    length as parameters

3 - Declare left = 0 because we start at the 1st element. declare right
    to len(nums) - 1 because the valid indexes are from 0 to 3. Meaning
    nums[4] doesn't exist and it will be out of bounds
    
4 - Set the while loop left <= right because binary search shrinks the
    search space by adjusting left and right, and this algorithm is
    used for arrays of ascending order

5 - Declare mid = (left + right) // 2 because we want the middle index.
    Binary search works by checking the middle element, then deciding
    whether to search the left half or the right half.

6 - If nums[mid] == target: we found it → return mid.
    If nums[mid] < target: the target must be to the right of mid.
    So, move the left boundary up: left = mid + 1.

    If nums[mid] > target: the target must be to the left of mid.
    So, move the right boundary down: right = mid - 1.

7 - If the target wasn’t found, left will stop at the position
    where the target should be inserted.


"""

class Solution:
    def searchInsert(self, nums, target):

        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            
            elif nums[mid] < target:
                left = mid + 1

            else:
                if nums[mid] > target:
                    right = mid - 1

        return left
    
sol = Solution()

nums = [1,3,5,6]
target = 7

print(sol.searchInsert(nums, target))