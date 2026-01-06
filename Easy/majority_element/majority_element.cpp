#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int candidate = 0;

            for(int i = 0; i < nums.size(); i++){
                if(count == 0){
                    candidate = nums[i];
                }
                if(nums[i] == candidate){
                    count++;
                } else {
                    count--;
                }
            }
            return candidate;
        }
};

//Example usage:
int main(){
    Solution solution;
    vector<int> nums1 = {3, 2, 3};
    int result1 = solution.majorityElement(nums1);
    cout << "For the input [3, 2, 3], the majority element is: " << result1 << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    int result2 = solution.majorityElement(nums2);
    cout << "For the input [2, 2, 1, 1, 1, 2, 2], the majority element is: " << result2 << endl;

    return 0;
}