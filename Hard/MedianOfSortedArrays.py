"""


PROBLEM


Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106


STEPS


1 - The class has a function that takes in 2 Lists as parameters
2 - We must create a third list called merged that consist of list1 and
    list2 and they must be in the sorted method

3 - We must find the length of the merged list (n)
4 - We must have a middle value so that we can use it to find the median

5 - If checks whether n is divisible by 2 or not and if the condition is
    true, we return merged at position mid-1 + merged at position mid
    divided by 2 because if our n is an even number, the median will
    consist of 2 values so we have to divide them by 2

6 - Else returns merged at position mid inside float because if n is an
    odd number, the position of the median is going to be a single value
    and that single value is merged at position mid


"""

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = sorted(nums1 + nums2)
        n = len(merged)
        mid = n // 2
        
        if n % 2 == 0:
            return (merged[mid-1] + merged[mid]) / 2
        else:
            return float(merged[mid])
        
sol = Solution()
nums1 = [1,2]
nums2 = [3,4]
result = sol.findMedianSortedArrays(nums1, nums2)
print(result)
        