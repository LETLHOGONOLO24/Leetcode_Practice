
/*



*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> twoSums(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // stores value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement already exists in the map
            if (seen.find(complement) != seen.end()) {
                return { seen[complement], i };
            }

            // otherwise, store the current number and its index
            seen[nums[i]] = i;
        }

        return {}; // problem guarantees there is always one solution
    }
};

int main() {
    Solution sol;

    int target1 = 9;
    vector<int> nums1 = { 2,7,11,15 };

    int target2 = 6;
    vector<int> nums2 = { 3,3 };

    vector<int> result1 = sol.twoSums(nums1, target1);
    vector<int> result2 = sol.twoSums(nums2, target2);

    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}

