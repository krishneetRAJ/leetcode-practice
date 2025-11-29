#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums){
            unordered_set<int> unique(nums.begin(), nums.end());
            if(unique.size() == nums.size()){
                return false;
            }else{
                return true;
            }
        }
};

// Example usage:
int main(){
    cout << boolalpha; // to print bool values as true/false
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = solution.containsDuplicate(nums1); 
    cout << "For the input [1, 2, 3, 1], the output is: " << result1 << endl; 

    Solution solution2;
    vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = solution2.containsDuplicate(nums2);
    cout << "For the input [1, 2, 3, 4], the output is: " << result2 << endl;

    Solution solution3;
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    bool result3 = solution3.containsDuplicate(nums3);
    cout << "For the input [1, 1, 1, 3, 3, 4, 3, 2, 4, 2], the output is: " << result3 << endl;
    return 0;
}