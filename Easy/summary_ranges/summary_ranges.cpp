#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> result;
            int i = 0;
            while(i < nums.size()) {
                int start = nums[i];
                while(i + 1 < nums.size() && nums[i] + 1 == nums[i+1]) {
                    i++;
                }
                int end = nums[i];
                if(start == end) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
                i++;
            }
            return result;
        }
};

//Example usage:
int main() {
    Solution solution1;
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = solution1.summaryRanges(nums1);
    cout << "Testing Summary Ranges: " << endl;
    cout << "Input: nums = [0, 1, 2, 4, 5, 7]" << endl;
    cout << "Output: [";
    for(int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if(i != result1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "" << endl;

    Solution solution2;
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result2 = solution2.summaryRanges(nums2);
    cout << "Input: nums = [0, 2, 3, 4, 6, 8, 9]" << endl;
    cout << "Output: [";
    for(int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if(i != result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "" << endl;
    return 0;
}