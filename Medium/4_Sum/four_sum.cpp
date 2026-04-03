#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<vector<int>> result;

            for(int i = 0; i < n-3; i++) {
                if(i > 0 && nums[i] == nums[i-1]) {
                    continue; // Skip duplicates for the first number
                }
                for(int j = i+1; j < n-2; j++) {
                    if(j > i+1 && nums[j] == nums[j-1]) {
                        continue;
                    }
                    int left = j + 1;
                    int right = n - 1;
                    while(left < right) {
                        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right]; // Use long long to prevent overflow
                        if(sum == target) {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            left++;
                            right--;
                            while(left < right && nums[left] == nums[left - 1]) {
                                left++;
                            }
                            while(left < right && nums[right] == nums[right + 1]) {
                                right--;
                            }
                        }
                        else if(sum < target) {
                            left++;
                        } else {
                            right--;
                        }
                    }
                }
            }
            return result;
        }
};

//Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = solution1.fourSum(nums1, target1);
    cout << "Testing Four Sum: " << endl;
    cout << "Input: nums = [1, 0, -1, 0, -2, 2], target = 0" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl; // [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

    Solution solution2;
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = solution2.fourSum(nums2, target2);
    cout << "" << endl;
    cout << "Input: nums = [2, 2, 2, 2, 2], target = 8" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j];
            if (j < result2[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl; // [[2, 2, 2, 2]]
};