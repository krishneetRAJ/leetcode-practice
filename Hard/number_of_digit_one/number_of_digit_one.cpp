#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int countDigitOne(int n) {
            int count = 0;
            long factor = 1;

            while (factor <= n) {
                long lower = n % factor;
                long current = (n / factor) % 10;
                long higher = n / (factor * 10);

                if (current == 0) {
                    count += higher * factor;
                }
                else if (current == 1) {
                    count += higher * factor + lower + 1;
                }
                else {
                    count += (higher + 1) * factor;
                }

                factor *= 10;
            }

            return count;
    }
};

int main() {
    Solution solution;
    vector<int> testCases = {13, 0};
    for (int n : testCases) {
        int result = solution.countDigitOne(n);
        cout << "Number of digit '1' from 1 to " << n << ": " << result << endl;
    }
    return 0;
}