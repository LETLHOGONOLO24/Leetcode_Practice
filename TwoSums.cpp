/*
* 
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
* 
* 
* STEPS
* 
* 1 - We use a vector function that  takes a vector, and an integer as parameters
* 2 - We have to declare an unordered map to store velue:index
* 
* 3 - Use a for loop to loop through the vector parameter using the size of the
*   vector
* 4 - Inside the for loop:
*   declare complement to be target - nums[i] WHY because nums[j] is another
*   name for complement so we must subtract target from nums[i]
*   
*   - The if statement is going to check if the complement exists in the map
*   seen.find(complement) != seen.end() says lets say 7 is the complement and
*   it must not be equal to end() which points after the last element
* 
*   - So 7 is != to end() will return a key value of {seen[7], 0}
*   - If the if condition is false, seen[2] = 0 - complement = 9-2 (nums[i] = 2
* 
* 5 - The vector function must return an empty vector {}
* 6 - Inside the main function, you must declare an object that you can use to
*   access the vector function of the class
* 
* 7 - You must declare a vector that you're going to use as your argument when
*   calling the vector function using the object
*   
* 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // stores value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // another name for complement is nums[j]

            // check if complement already exists in the map
            if (seen.find(complement) != seen.end()) {
                return { seen[complement], i };
            }

            // otherwise, store the current number and its index
            seen[nums[i]] = i; // seen[2] = 0 means key = 2, value = 0
        }

        return {}; // problem guarantees there is always one solution
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}


/*

*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*
*You may assume that each input would have exactly one solution, and you may not use the same element twice.
*
*You can return the answer in any order.
*
*
*
*Example 1:
*
*Input: nums = [2,7,11,15], target = 9
*Output: [0,1]
*Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*Example 2:
*
*Input: nums = [3,2,4], target = 6
*Output: [1,2]
*Example 3:
*
*Input: nums = [3,3], target = 6
*Output: [0,1]
*
*
*Constraints:
*
*2 <= nums.length <= 104
*-109 <= nums[i] <= 109
*-109 <= target <= 109
*Only one valid answer exists.

*/