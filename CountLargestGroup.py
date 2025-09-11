"""

You are given an integer n.

We need to group the numbers from 1 to n according to the sum of its digits. For example, the numbers 14 and 5 belong to the same group, whereas 13 and 3 belong to different groups.

Return the number of groups that have the largest size, i.e. the maximum number of elements.

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

Constraints:

1 <= n <= 104

if n = 13
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].

if n = 15
[1,10], [2,11], [3,12], [4,13], [5,14], [6,15], [7], [8], [9].

if n = 25
[1,10], [2,11], [3,12], [4,13], [5,14], [6,15], [7,16], [8,17], [9,18].
[10], [11], until [25]



*Step 1 Compute the digit sum
    -Each number in the range must have a sum
    -Operation for digit sum:

        For 1
        Last digit: 1 % 10 = 1 → add to sum → sum = 1
        Remaining number: 1 // 10 = 0 → stop (no more digits)
        digit sum = 1

        For 10
        Last digit: 10 % 10 = 0 → add to sum → sum = 0
        Remaining number: 10 // 10 = 1 → continue
        Last digit: 1 % 10 = 1 → add to sum → sum = 0 + 1 = 1
        Remaining number: 1 // 10 = 0 → stop
        digit sum = 1

    -We can loop through n, initialize sum = 0 inside the loop
    so that when the 2nd iteration is looping, sum is reset to 0,
    initialize a while to loop through n > 0 and check last digit
    and remaining digit

    -Add sum to the result of iteration % 10
    -Equate number to number // 10 so that when number = 0, the
    loop stops since the condition is n > 0

*Step 2 Keep track of groups
    -We're going to use a dictionary to count how many numbers fall
    into each digit sum group

    -What that means is that the dictionary is going to count digit
    sums that have the same value

        Key - digit sum: Value - count of how many digit sums are equal
            to 1,2,3,4 etc

    -The dictionary is going to hold all the digit sums from 1 to n

*Step 3 Find the largest group size

*Step 4 Count how many groups have that size

*Step 5 Return the answer


So everytime a loop loops through n, it must:
    compute the digit sum
    group the digit sum with the count inside dictionary




"""

def countLargestGroup(n):

    # Step 1: function to compute digit sums
    def digit_sum(x):
        total = 0
        while x > 0:
            total += x % 10
            x //= 10
        return total
    
    # Step 2: dictionary to keep track of groups
    groups = {}

    for i in range(1, n+1): # 0 <= n <= 10000
        s = digit_sum(i)
        groups[s] = groups.get(s, 0) + 1

    # Step 3: Find max group size
    max_size = max(groups.values())

    # Step 4: count how many groups have this max size
    return sum(1 for size in groups.values() if size == max_size)

print(countLargestGroup(25))
print(countLargestGroup(2))
        

        
    

    