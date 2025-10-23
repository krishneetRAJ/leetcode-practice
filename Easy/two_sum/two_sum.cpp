#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> num_to_index;
            for (int i = 0; i < nums.size(); i++) {
                int difference = target - nums[i];
                if (num_to_index.find(difference) != num_to_index.end()) {
                    return {num_to_index[difference], i};
                }
                num_to_index[nums[i]] = i;
            }
            return {};
        }
};

// Example usage:
int main(){
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = solution.twoSum(nums, 9);
    cout << "For the input {2, 7, 11, 15} with target 9, the output is: [" << result[0] << ", " << result[1] << "]" << endl;

    Solution solution2;
    vector<int> nums2 = {3, 2, 4};
    vector<int> result2 = solution.twoSum(nums2, 6);
    cout << "For the input {3, 2, 4} with target 6, the output is: [" << result2[0] << ", " << result2[1] << "]" << endl;

    Solution solution3;
    vector<int> nums3 = {3, 3};
    vector<int> result3 = solution.twoSum(nums3, 6);
    cout << "For the input {3, 3} with target 6, the output is: [" << result3[0] << ", " << result3[1] << "]" << endl;
}