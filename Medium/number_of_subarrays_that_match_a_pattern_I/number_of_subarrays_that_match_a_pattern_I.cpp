#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        for (int i = 0; i < n - m; i++) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (pattern[j] == 1 && nums[i + j + 1] <= nums[i + j]) {
                    match = false;
                    break;
                }
                else if (pattern[j] == 0 && nums[i + j + 1] != nums[i + j]) {
                    match = false;
                    break;
                }
                else if (pattern[j] == -1 && nums[i + j + 1] >= nums[i + j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                count++;
            }
        }

        return count;
    }
};

// Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    vector<int> pattern1 = {1, 1};
    int result1 = solution1.countMatchingSubarrays(nums1, pattern1);
    cout << "For the input [1, 2, 3, 4, 5, 6] and pattern [1, 1], the number of matching subarrays is: " << result1 << endl;

    Solution solution2;
    vector<int> nums2 = {1, 4, 4, 1, 3, 5, 5, 3};
    vector<int> pattern2 = {1, 0, -1};
    int result2 = solution2.countMatchingSubarrays(nums2, pattern2);
    cout << "For the input [1, 4, 4, 1, 3, 5, 5, 3] and pattern [1, 0, -1], the number of matching subarrays is: " << result2 << endl;

    return 0;
};