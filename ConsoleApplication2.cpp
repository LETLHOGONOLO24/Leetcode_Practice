// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

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

