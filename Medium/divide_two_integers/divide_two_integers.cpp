#include <iostream>
#include <vector>  
#include <string>
using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == -2147483648LL && divisor == -1) {
                return 2147483647; // Using this because the maximum value of a 32-bit signed integer is 2147483647 and if I did it normally it would overflow
            }
            bool negative = false;
            if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
                negative = true;
            }
            long long ldividend = labs(dividend); //Creating a long long variable to store the absolute value of dividend
            long long ldivisor = labs(divisor);   //Creating a long long variable to store the absolute value of divisor
            if(ldividend < 0){
                ldividend = -(ldividend);
            }
            if(ldivisor < 0){
                ldivisor = -(ldivisor);
            }
            long long lquotient = 0;
            while(ldividend >= ldivisor) {
                long long temp = ldivisor, multiple = 1;
                while(ldividend >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }
                ldividend -= temp;
                lquotient += multiple;
            }
            if(negative) {
                lquotient = -lquotient;
            }
            return lquotient;
        }
};

int main(){
    Solution sol1;
    int dividend = 10;
    int divisor = 3;
    cout << "Result of " << dividend << " divided by " << divisor << " is: " << sol1.divide(dividend, divisor) << endl;

    Solution sol2;
    dividend = 7;
    divisor = -3;
    cout << "Result of " << dividend << " divided by " << divisor << " is: " << sol2.divide(dividend, divisor) << endl;
    return 0;

}