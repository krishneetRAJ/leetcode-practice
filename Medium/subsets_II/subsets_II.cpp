#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result = {{}};
            int start = 0;

            for (int i = 0; i < nums.size(); i++) {
                vector<vector<int>> currentSubsets;

                if (i > 0 && nums[i] == nums[i - 1]) {
                    for (int j = start; j < result.size(); j++) {
                        currentSubsets.push_back(result[j]);
                    }
                } else {
                    currentSubsets = result;  // makes a copy
                }

                start = result.size();

                for (vector<int> subset : currentSubsets) {
                    subset.push_back(nums[i]);
                    result.push_back(subset);
                }
            }

            return result;
        }
};

// Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> result1 = solution1.subsetsWithDup(nums1);
    cout << "Testing Subsets II: " << endl;
    cout << "Input: nums = [1, 2, 2]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "[";
        for (int j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j != result1[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "" << endl;

    Solution solution2;
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = solution2.subsetsWithDup(nums2);
    cout << "Input: nums = [0]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "[";
        for (int j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j];
            if (j != result2[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}