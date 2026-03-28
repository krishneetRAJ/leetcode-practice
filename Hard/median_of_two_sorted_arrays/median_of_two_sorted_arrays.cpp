#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        int total = m + n;
        int mid1 = (total-1) / 2; // For odd total, mid1 and mid2 will be the same
        int mid2 = total / 2;

        int i = 0, j = 0, count = 0;
        int val1 = 0, val2 = 0;
        while(count <= mid2) {
            int current;
            if(i < m && (j >= n || nums1[i] < nums2[j])) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
            if(count == mid1) {
                val1 = current;
            }
            if(count == mid2) {
                val2 = current;
            }
            count++;
        }
        return double((val1 + val2) / 2.0);
    }
};

int main() {
    Solution sol1;
    vector<int> nums1_1 = {1, 3};
    vector<int> nums1_2 = {2};
    cout << "Median of [1, 3] and [2]: " << fixed << setprecision(1) << sol1.findMedianSortedArrays(nums1_1, nums1_2) << endl;

    Solution sol2;
    vector<int> nums2_1 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Median of [1, 2] and [3, 4]: " << fixed << setprecision(1) << sol2.findMedianSortedArrays(nums2_1, nums2_2) << endl;
    return 0;
}