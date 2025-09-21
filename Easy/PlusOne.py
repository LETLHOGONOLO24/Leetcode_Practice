"""

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.


STEPS


1 - range(n-1, -1, -1) means:
    Start at the last digit (n-1)
    Go down to the first digit (-1 means "stop before -1", so 0)
    Step backwards by 1 each time (-1)

2 - Why check if < 9? Because if a digit is 0-8, adding 1 won't
    cause a carry-over!
3 - digits[i] += 1 means we add 1 to this digit. For e.g. If digit
    was 3, it becomes 4

4 - return digits means we immediately return because if we don't
    need to carry over, we're done!
5 - else means the digit is exactly 9 and adding 1 to 9 gives 10,
    which means we need to carry over

6 - digits[i] = 0 means when we add 1 to 9, we get 10. We write
    down 0 and carry over the 1 to the next digit. The loop continues
    to the next digit to the left

    For e.g. [1,9,9] -> Look at last digit: 9 → set to 0, carry over,
    Look at middle digit: 9 → set to 0, carry over, Look at first digit:
    1 → becomes 2, return [2, 0, 0]

7 - return [1] + [0] * n means [1] = Add a new 1 at the beginning (the
    carried-over 1), [0] * n = Add n zeros (because all original digits
    became 0), So [9, 9, 9] (n=3) becomes [1] + [0, 0, 0] = [1, 0, 0, 0] 


"""

class Solution:
    def plusOne(self, digits):
        n = len(digits)
        # Start from the last digit
        for i in range(n-1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits # No carry needed, return immediately
            else:
                digits[i] = 0 # Set to 0 and carry over to the next digit
        # If we finish the loop, it means every digit was 9 and we have a final carry
        return [1] + [0] * n # Or [1] + digits (since digits is now all zeros)

            


sol = Solution()

digits = [9,9,9]
result = sol.plusOne(digits)
print(result)
