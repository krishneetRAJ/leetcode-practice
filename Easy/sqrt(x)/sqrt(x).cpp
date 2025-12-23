#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            if(x == 0){
                return 0;
            }
            int left = 1, right = x, answer = 0;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(mid <= x / mid){
                    answer = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return answer;
        }
};

//Example usage:
int main(){
    Solution solution;
    int x1 = 4;
    cout << "The integer square root of " << x1 << " is: " << solution.mySqrt(x1) << endl;

    int x2 = 8;
    cout << "The integer square root of " << x2 << " is: " << solution.mySqrt(x2) << endl;
}