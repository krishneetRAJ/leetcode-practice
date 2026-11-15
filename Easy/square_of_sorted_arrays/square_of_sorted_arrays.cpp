#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size();
            vector<int> result(n);
            int left = 0, right = n - 1;
            int pos = n - 1;

            while (left <= right) {
                if (abs(nums[left]) > abs(nums[right])) {
                    result[pos] = nums[left] * nums[left];
                    left++;
                } else {
                    result[pos] = nums[right] * nums[right];
                    right--;
                }
                pos--;
            }

            return result;
        }
};

// Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> result1 = solution1.sortedSquares(nums1);
    cout << "For the input [-4, -1, 0, 3, 10], the sorted squares are: ";
    cout << "[";
    size_t result1Size = result1.size();
    for (size_t i = 0; i < result1Size; ++i) {
        cout << result1[i];
        if (i + 1 < result1Size) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;       

    Solution solution2;
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    vector<int> result2 = solution2.sortedSquares(nums2);
    cout << "For the input [-7, -3, 2, 3, 11], the sorted squares are: ";
    cout << "[";
    size_t result2Size = result2.size();
    for (size_t i = 0; i < result2Size; ++i) {
        cout << result2[i];
        if (i + 1 < result2Size) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;   
    return 0;
};