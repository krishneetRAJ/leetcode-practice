#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int counter = 1;
        int maximum = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i+1] - nums[i] == 1){
                counter++;
            }else if(nums[i+1] - nums[i] == 0){
                counter = counter + 0;
            }else{
                counter = 1;
            }
            if(counter > maximum){
                maximum = counter;
            }
        }
        return maximum;
    }
};

int main(){
    Solution solution1;
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    int result1 = solution1.longestConsecutive(nums1);
    cout << "Longest Consecutive Sequence in [100, 4, 200, 1, 3, 2] is: " << result1 << endl;

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    int result2 = solution1.longestConsecutive(nums2);
    cout << "Longest Consecutive Sequence in [0,3,7,2,5,8,4,6,0,1] is: " << result2 << endl;

    vector<int> nums3 = {1,0,1,2};
    int result3 = solution1.longestConsecutive(nums3);
    cout << "Longest Consecutive Sequence in [1,0,1,2] is: " << result3 << endl;
    return 0;
}