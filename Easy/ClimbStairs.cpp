/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct
ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45


STEPS


1 - n == 1 and n == 2 are base cases. If there's only 1 step, there's
    exactly 1 way to climb it (take one 1-step). With 2 steps, there
    are 2 ways: [1,1] or [2]. These first two cases are our foundation.

2 - int two_steps_back = 1;  This variable represents "how many ways to
    reach the step that is 2 steps before our current position." We initialize
    it to 1 because that's ways(1) - the number of ways to reach step 1.

3 - int one_step_back = 2; This represents "how many ways to reach the step that
    is 1 step before our current position." We initialize it to 2 because that's
    ways(2) - the number of ways to reach step 2.

4 - int current = 0; This will store the result for the current step we're
    calculating.
5 - for (int i = 2; i < n; i++) { We already know the answers for steps 1 and 2.
    Now we need to calculate steps 3 through n. The loop starts at i = 2 but we're
    actually calculating step i+1 each iteration.

    When i = 2, we're calculating ways(3)
    When i = 3, we're calculating ways(4)
    And so on until we reach ways(n)

6 - The number of ways to reach the current step equals the sum of ways to reach the
    previous two steps. Why? Because your last move was either

    A 1-step move (from one_step_back)
    A 2-step move (from two_steps_back)

7 - two_steps_back = one_step_back; After calculating the current step, we "slide our
    window" forward. What was previously "one step back" now becomes "two steps back"
    for the next iteration.

8 - one_step_back = current; The current step we just calculated becomes the new "one
    step back" for the next iteration.



*/

#include <iostream>
using namespace std;

class Solution {
    public:
    int climbStairs(int n) {
        
        if (n == 1) { // base case 1
            return 1; // base case 2
        }

        if (n == 2) {
            return 2;
        }

        int two_steps_back = 1; // ways to reach step 1
        int one_step_back = 2; // ways to reach step 2
        int current = 0;

        // Build up from step 3 to step n

        for (int i = 2; i < n; i++) {
            current = one_step_back + two_steps_back;
            two_steps_back = one_step_back; // Move our window forward
            one_step_back = current; // Move our window forward
        }

        return current;
    }
};

int main() {

    Solution sol;

    int n = 4;
    int result = sol.climbStairs(n);
    cout << result << endl;
    return 0;
}