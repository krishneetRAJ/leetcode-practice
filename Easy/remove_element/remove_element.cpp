#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] != val){
                    nums[i] = nums[j];
                    i++;
                }
            }
            return i;
        }
};

//Example usage:
int main(){
    Solution solution;
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int new_length1 = solution.removeElement(nums1, val1);
    cout << "After removing " << val1 << " from [3, 2, 2, 3], the new array is: ";
    cout << "[";
    for (int i = 0; i < new_length1; i++) {
        cout << nums1[i];
        if (i < new_length1 - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int new_length2 = solution.removeElement(nums2, val2);
    cout << "After removing " << val2 << " from [0, 1, 2, 2, 3, 0, 4, 2], the new array is: ";
    cout << "[";
    for(int i = 0; i < new_length2; i++){
        cout << nums2[i];
        if (i < new_length2 - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}