
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> twoSums(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n-1; i++) {
            for (int j = n+1; j < n; j++) {
                if ((nums[i] + nums[j]) == target) {
                    cout << "[" << i << "," << j << "]" << endl;
                }
            }
        }
    }
};

int main() {
    Solution sol;

    int target1 = 9;
    vector<int> nums1 = {2,7,11,15};

    int target2 = 6;
    vector<int> nums2 = {3,3};


    sol.twoSums(nums1, target1);
    sol.twoSums(nums2, target2);

    return 0;
}