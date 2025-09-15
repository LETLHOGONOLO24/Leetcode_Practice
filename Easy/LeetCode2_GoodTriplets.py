"""
arr = [3,0,1,1,9,7], a=7, b=2, c=3


[3,0,1]
Since 0 <= i < j < k < arr.length

Step 1 (We start at 0,1,2) ---
Pick i = 0 → arr[0] = 3; Since 0 <= i < j < k < arr.length
Pick j = 1 → arr[1] = 0
Pick k = 2 → arr[2] = 1

- for step 1, we satisfy the 0 <= i < j < k < arr.length rule

Step 2 [3,0,1]
|arr[i] - arr[j]| = |3-0| = 3 <= 7
|arr[j] - arr[k]| = |0-1| = |-1| = 1 <= 2          [YES]
|arr[i] - arr[k]| = |3-1| = 2 <= 3

- for step 2, we must satisfy the Must be ≤ a,b,c rule


[3,0,1]
Step 1 [3,0,1]
Pick i = 0 → arr[0] = 3;
Pick j = 1 → arr[1] = 0;
Pick k = 3 → arr[3] = 1;

- for us to use k=3 in step 1 is because since we tried k=2, we must try k=3
    Now, to find all triplets, we must try all possible indices k greater than j

    i = 0
    j = 1
    k can be any index greater than 1 → 2, 3, 4, 5
    k=4 → (3,0,9) ❌ fails conditions (doesnt satisfy step 2 rule)
    k=5 → (3,0,7) ❌ fails conditions (doesnt satisfy step 2 rule)

    
[3,1,1]    
Step 1 [3,1,1]
Pick i = 0 → arr[0] = 0; Since 0 <= i < j < k < arr.length
Pick j = 2 → arr[1] = 1
Pick k = 3 → arr[2] = 1

-For step 1, since k=4 fails the condition, we're stuck at k=3, but for j,
 we can go from j=1 -> j=2 which still falls in the
 0 <= i < j < k < arr.length range

Step 2 [3,1,1]
|arr[i] - arr[j]| = |3-1| = 2 <= 7
|arr[j] - arr[k]| = |1-1| = 0 <= 2          [YES]
|arr[i] - arr[k]| = |3-1| = 2 <= 3


[0,1,1]
Step 1 [0,1,1]
Pick i = 1 → arr[0] = 0; Since 0 <= i < j < k < arr.length
Pick j = 2 → arr[1] = 1
Pick k = 3 → arr[2] = 1

- for step 1, we satisfy the 0 <= i < j < k < arr.length rule

Step 2 [0,1,1]
|arr[i] - arr[j]| = |0-1| = 1 <= 7
|arr[j] - arr[k]| = |1-1| = 0 <= 2                 [YES]
|arr[i] - arr[k]| = |0-1| = 1 <= 3

-for step 2, we must satisfy the Must be ≤ a,b,c rule



Step 2 [1,1,9]
|arr[i] - arr[j]| = |1-1| = 0 <= 7
|arr[j] - arr[k]| = |1-9| = |-8| = 8 > 2 (Wrong)  
|arr[i] - arr[k]| = |1-9| = |-8| 8 > 3

[1,9,7]
|arr[i] - arr[j]| = |1-9| = 8 > 7
|arr[j] - arr[k]| = |9-7| = |-1| = 1 <= 2 (Wrong)
|arr[i] - arr[k]| = |3-1| = 2 <= 3

*[3,0,1] and [0,1,1] 

i = 0, j = 2, k = 3 -> [3,1,1]

for i in range(0, len(arr) - 3):
    for j in range()


    


arr = [3,0,1,1,9,7], a=7, b=2, c=3

"""

"""

1. range(0, len(arr)-2) is for looping from arr[0] to
    arr[3] because i=0, j=1, k=2

2. range(i+1, len(arr)-1)) is for looping from arr[1] to
    arr[4] because it has to check i=1, j=2, k=3 and for
    that to be possible, j has to loop from [1] to
    arr[4] to leave room for k or only check 3 numbers 
    from arr[1] since a[0] has been checked 

3. range(j+1, len(arr)) is for looping the last 3 digits by
    starting from arr[2] to arr[5] which starts at arr[3] =
    1 -> [1,9,7]

4. if abs(arr[i] - arr[j]) <= a and \
        abs(arr[j] - arr[k]) <= b and \
        abs(arr[i] - arr[k]) <= c:

        count += 1 must be in line with the if stmt

5. return count must be in line with the for loop
    \ means this continues on the next line

"""

class Solution:
    def countGoodTriplets(self, arr, a, b, c):

        count = 0
        n = len(arr)

        # Lets start looping through i,j,k
        for i in range(0, n-2): #1
            for j in range(i+1, n-1): #2
                for k in range(j+1, n): #3

                    #4 Lets check the conditions Must <= a,b,c
                    if abs(arr[i] - arr[j]) <= a and \
                         abs(arr[j] - arr[k]) <= b and \
                         abs(arr[i] - arr[k]) <= c:
                        
                        count += 1
          
        #5 Return count when arr, a, b, and c are provided            
        return count
    

arr = [3,0,1,1,9,7]
a, b, c = 7, 2, 3

sol = Solution()
print(sol.countGoodTriplets(arr, a, b, c))
        
    

    