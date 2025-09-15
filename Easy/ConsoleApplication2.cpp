
/*

Given a 0-indexed integer array nums of length n and an integer k, 
return the number of pairs (i, j) where 0 <= i < j < n, 
such that nums[i] == nums[j] and (i * j) is divisible by k.


Example 1:

Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
Example 2:

Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.


- Any number (a) that is divisible by a number (b) is not equal to 0
    So 0 is divisible by 2 because the remainder is 0

- Start by initializing count = 0;

- Lets say we loop for i, it must leave room for j to check the last element
    for i in range(0, len(arr)-1):
        for j in range(i+1, len(arr)):

    - Every time its looping it checks if:
    if (arr[i] == arr[j] && (arr[i] * arr[j]) % 2 == 0 ) {
        count += 1;

    - Return count
    - Create an object to be able to have access to the method

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }


};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 1, 2, 2, 2, 1, 3};
    int k1 = 2;
    cout << "Output 1: " << sol.countPairs(nums1, k1) << endl;

    vector<int> nums2 = { 1, 2, 3, 4 };
    int k2 = 1;
    cout << "Output 2: " << sol.countPairs(nums2, k2) << endl;
    
    return 0;
}

