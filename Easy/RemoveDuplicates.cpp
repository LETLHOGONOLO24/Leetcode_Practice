/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.


STEPS


1 - Declare a function that takes in a vector. The & operator means
    we should pass nums by reference not by value. If we pass by value,
    a copy of the vector is made, and any changes made will not affect
    the original vector in main

2 - The if statement checks whether the vector is empty, and if it's 
    indeed empty, 0 will be returned

3 - We set k to 1 because since k is meant to count how many unique
     elements we've found so far, the first element doesn't need any
     comparison, there's nothing before it, so it must be unique. That's
     why we initialize k = 1 because we've already found one unique 
     element at index 0

4 - The i of the for loop starts at 1 because we have to compare the
    2nd element to the first. The if statement says if nums[1] !=
    nums[0], we skip because they are equal, but if they are not equal
    like nums[2] != nums[1], nums[1] = nums[2] which means the 2nd
    iterator nums[1] is now 1 and we increment k to count the unique
    values

5 - In the main function, when we set k to sol.removeDuplicates(nums1),
    we say the function removeDuplicates to perform its operations on
    nums1 and return k

6 - The for loop will loop from 0 until k and print out every iteration

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0,0,1,1,1,2,2,3,3,4};

    int k = sol.removeDuplicates(nums1);

    cout << "Unique number: " << k << endl;
    cout << "Unique numbers: ";
    for (int i = 0; i < k; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}