"""

Given a non-negative integer x, return the square root of x rounded down 
to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it
down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1


STEPS 


1 - if x == 0 or x == 1: return x handles he simplest cases immediately
    because square root of 0 is 0 and square root of 1 is 1 (Special Case)
2 - left = 1 sets the starting point of our search range to 1 because we
    know the square root of x must be at least 1 (since we handled 0)

3 - right = x sets the ending point of our search range to x itself because
     the square root of x cannot be larger than x (for x >= 1)
4 - answer = 0 creates a variable to store our best guess so far because
    we need to remember the closest number we found that works

5 - while left <= right keeps  searching as long as there's a valid range to
    check because this is a binary search - we repeatedly cut the search range
    in half

6 - mid = left + (right - left) // 2 finds the middle number between left and
    right. Instead of (left + right) // 2, we use this formula to avoid overflow

7 - square = mid * mid squares the middle number to test if it's the square root
    because we're checking if mid x mid equals our target x

8 - if square == x: return mid says If mid x mid exactly equals x, we found the
    perfect square root!

9 - If square or mid x mid is < x, mid might be our answer. left = mid +
    1: Search in the upper half (try larger numbers) because since mid x mid < x,
    the real answer might be bigger than mid

10 - square > x checks if mid x mid is greater than x, mid is too big. right = mid
    - 1: Search in the lower half (try smaller numbers) because since mid x mid > x
    the real answer must be smaller than mid



"""

class Solution:
    def mySqrt(self, x):

        if x == 0 or x == 1:
            return x

        left = 1
        right = x
        answer = 0

        while left <= right:
            mid = left + (right - left) // 2

            square = mid * mid

            if square == x:
                return mid
            
            if square < x:
                answer = mid
                left = mid + 1

            elif square > x:
                right = mid - 1

        return answer
    
sol = Solution()

x = 4
y = 8

print(sol.mySqrt(x))
print(sol.mySqrt(y))
        