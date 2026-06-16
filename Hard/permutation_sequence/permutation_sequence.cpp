#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> factorial(n, 1);
            for(int i = 1; i < n; i++) {
                factorial[i] = factorial[i-1] * i;
            }
            vector<int> numbers;
            for(int i = 1; i <= n; i++) {
                numbers.push_back(i);
            }
            k--; // Convert to zero-based index
            string result;
            for(int i = n - 1; i >= 0; i--) {
                int index = k / factorial[i];
                result += to_string(numbers[index]);
                numbers.erase(numbers.begin() + index); // Remove used number
                k %= factorial[i];
            }
            return result;
        }
};

// Example usage:
int main() {
    Solution solution1;
    int n1 = 3, k1 = 3;
    string result1 = solution1.getPermutation(n1, k1);
    cout << "Testing Permutation Sequence: " << endl;
    cout << "Input: n = 3, k = 3" << endl;
    cout << "Output: " << result1 << endl;

    cout << "" << endl;
    Solution solution2;
    int n2 = 4, k2 = 9;
    string result2 = solution2.getPermutation(n2, k2);
    cout << "Input: n = 4, k = 9" << endl;
    cout << "Output: " << result2 << endl;

    cout << "" << endl;
    Solution solution3;
    int n3 = 3, k3 = 1;
    string result3 = solution3.getPermutation(n3, k3);
    cout << "Input: n = 3, k = 1" << endl;
    cout << "Output: " << result3 << endl;

    return 0;
}