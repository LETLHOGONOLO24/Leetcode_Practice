/*
* Given an integer n, return a list of two integers [a, b] where:
* a and b are No-Zero integers. a + b = n
* The test cases are generated so that there is at least one valid solution.
* If there are many valid solutions, you can return any of them.
*
* Input = 11
* Output = [1,1] or [2,9]
*
* STEPS
*
* 1. Initialize a vector function that will take any integer no matter the
* size
* 2. Use a for loop that will start from 1, count from 1 to n, set b to be
* equal to n - a
* 3. Use an if to check whether a number is a zero or not using the isNoZero
* function
*
* 4. The isNoZero is a boolean function that checks an integer whether it is
* a zero or not by using a while loop to check whether the int is > 0, if the
* condition is true, the loop will use an if to check whether that integer is
* divisible by 10 and return false
* 5. But if the if condition is false, the process will continue and take
* that integer to divide it by 10 so that if the answer is a decimal that
* starts with 0, the loop stops and returns true
*
* 6.if the if condition inside the for loop is true, the function will return
* a vector with 2 elements inside a and b
*
*
*
*
*
*
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isNoZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return { a, b };
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    int n = 11;
    vector<int> result = sol.getNoZeroIntegers(n);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}