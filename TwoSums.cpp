#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
