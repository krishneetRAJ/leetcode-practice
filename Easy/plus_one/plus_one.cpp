#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            if(n==0){
                return {1};
            }
            for(int i = n-1; i >= 0; i--){
                if(digits[i] < 9){
                    digits[i]++;
                    return digits;
                }
                digits[i] = 0;
            }
            digits.insert(digits.begin(), 1);
            return digits;
        }
};

//Example usage:
int main(){
    Solution solution;
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "For the input [1, 2, 3], the output is: [";
    for(int i = 0; i < result1.size(); i++){
        cout << result1[i];
        if(i != result1.size() - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "For the input [4, 3, 2, 1], the output is: [";
    for(int i = 0; i < result2.size(); i++){
        cout << result2[i];
        if(i != result2.size() - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> digits3 = {9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "For the input [9], the output is: [";
    for(int i = 0; i < result3.size(); i++){
        cout << result3[i];
        if(i != result3.size() - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}