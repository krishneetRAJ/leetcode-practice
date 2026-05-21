#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            int m = s.size();
            int n = t.size();
            vector<unsigned int> ways(n+1, 0);
            ways[0] = 1; // Base case: there's one way to match an empty string
            for(int i = 0; i < m; i++) {
                for(int j = n-1; j >= 0; j--) {
                    if(s[i] == t[j]) {
                        ways[j+1] += ways[j];
                    }
                }
            }
            return ways[n];
        }
};

//Example usage:
int main() {
    Solution solution1;
    string s1 = "rabbbit";
    string t1 = "rabbit";
    int result1 = solution1.numDistinct(s1, t1);
    cout << "Testing Distinct Subsequences: " << endl;
    cout << "Input: s = \"rabbbit\", t = \"rabbit\"" << endl;
    cout << "Output: " << result1 << endl; 

    Solution solution2;
    string s2 = "babgbag";
    string t2 = "bag";
    int result2 = solution2.numDistinct(s2, t2);
    cout << "Input: s = \"babgbag\", t = \"bag\"" << endl;
    cout << "Output: " << result2 << endl;
};
