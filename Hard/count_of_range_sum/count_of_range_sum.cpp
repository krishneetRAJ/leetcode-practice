#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        // Build prefix sum
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }

    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1){
            return 0;
        }
        int mid = (left + right) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) + mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;

        for (int i = left; i < mid; i++) {
            while (k < right && prefix[k] - prefix[i] < lower) { 
                k++;
            }
            while (j < right && prefix[j] - prefix[i] <= upper) { 
                j++;
            }
            count += (j - k);
        }

        // Merge step
        vector<long long> temp;
        int i = left, r = mid;

        while (i < mid && r < right) {
            if (prefix[i] <= prefix[r]) {
                temp.push_back(prefix[i++]);
            } else {
                temp.push_back(prefix[r++]);
            }
        }

        while (i < mid) { 
            temp.push_back(prefix[i++]);
        }

        while (r < right) { 
            temp.push_back(prefix[r++]);
        }
        for (int t = 0; t < temp.size(); t++) {
            prefix[left + t] = temp[t];
        }

        return count;
    }
};

// Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {-2, 5, -1};
    int lower1 = -2, upper1 = 2;
    int result1 = solution1.countRangeSum(nums1, lower1, upper1);
    cout << "For the input [-2, 5, -1] with lower = -2 and upper = 2, the output is: " << result1 << endl;

    Solution solution2;
    vector<int> nums2 = {0};
    int lower2 = 0, upper2 = 0;
    int result2 = solution2.countRangeSum(nums2, lower2, upper2);
    cout << "For the input [0] with lower = 0 and upper = 0, the output is: " << result2 << endl;
    return 0;
}