"""

Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

-Step 1: if the number is a negative, its not a palindrome, so the
    program must return false
-Step 2: convert the number to a string using str()

-Step3: check if the string is equal to a reversed one using
string[::-1]
    If true, return ture and if false, well

-s[::-2] means start from end, move 2 steps at a time backwards and
skip every other character while reversing.

s[start:end:step]


"""

class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        
        s = str(x)
        if s == s[::-1]:
            return True
        else:
            return False
        return True
    
sol = Solution()
x = 121
print(sol.isPalindrome(x))
