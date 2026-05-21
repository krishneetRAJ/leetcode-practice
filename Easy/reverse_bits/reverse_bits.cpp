#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        int reverseBits(int n) {
            unsigned int result = 0; // Use unsigned int to handle the sign bit correctly
            for(int i = 0; i < 32; i++) {
                result <<= 1; // Shift result left to make room for the next bit
                result |= (n & 1); // Add the least significant bit of n to result
                n >>= 1; // Shift n right to process the next bit
            }
            return result; 
        }
};

//Example usage:
int main() {
    Solution solution1;
    int n1 = 43261596;
    int result1 = solution1.reverseBits(n1);
    cout << "" << endl;
    cout << "Testing Reverse Bits: " << endl;
    cout << "Input: n = 43261596" << endl;
    cout << "Output: " << result1 << endl; // Expected output: 964176192

    cout << "" << endl;
    Solution solution2;
    int n2 = 2147483644;
    int result2 = solution2.reverseBits(n2);
    cout << "Input: n = 2147483644" << endl;
    cout << "Output: " << result2 << endl; // Expected output: 3221225472
};