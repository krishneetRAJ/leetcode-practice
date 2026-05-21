#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int closest = nums[0] + nums[1] + nums[2]; 
            for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(currentSum - target) < abs(closest - target)) {
                    closest = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    return currentSum;
                }
            }
        }
        return closest;
    }
};

//Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    int result1 = solution1.threeSumClosest(nums1, target1);
    cout << "Testing 3 Sum Closest: " << endl;
    cout << "Input: nums = [-1, 2, 1, -4], target = 1" << endl;
    cout << "Output: " << result1 << endl;

    Solution solution2;
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    int result2 = solution2.threeSumClosest(nums2, target2);
    cout << "" << endl;
    cout << "Input: nums = [0, 0, 0], target = 1" << endl;
    cout << "Output: " << result2 << endl;
};