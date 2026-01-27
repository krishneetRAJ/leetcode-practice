#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //Sort the array first
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue; //Skip duplicates
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]}); //Found a triplet
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                } else if(sum < 0){
                    left++;
                } else{
                    right--;
                }
            }
        }
        return result;
    }
};

void printResult(const vector<vector<int>>& result){
    if (result.empty()) {
        cout << "[]" << endl;
        return;
    }
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main(){
    Solution solution1;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution1.threeSum(nums1);
    cout << "Triplets for nums1:" << endl;
    printResult(result1);
    vector<int> nums2 = {};
    vector<vector<int>> result2 = solution1.threeSum(nums2);
    cout << "Triplets for nums2:" << endl;
    printResult(result2);
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solution1.threeSum(nums3);
    cout << "Triplets for nums3:" << endl;
    printResult(result3);
    return 0;
}