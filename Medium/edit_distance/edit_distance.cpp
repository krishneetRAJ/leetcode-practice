#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();
            vector<int> previous(n+1);
            for(int j = 0; j <= n; j++) {
                previous[j] = j;
            }
            for(int i = 1; i <= m; i++) {
                vector<int> current(n+1);
                current[0] = i;
                for(int j = 1; j <= n; j++) {
                    if(word1[i-1] == word2[j-1]) {
                        current[j] = previous[j-1];
                    } else {
                        int insert = current[j-1];
                        int deleteChar = previous[j];
                        int replace = previous[j-1];
                        current[j] = 1 + min(insert, min(deleteChar, replace));
                    }
                }
                previous = current;
            }
            return previous[n];
        }
};

// Example usage:
int main() {
    Solution solution1;
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << solution1.minDistance(word1, word2) << endl;    

    Solution solution2;
    word1 = "intention";
    word2 = "execution";
    cout << "Minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << solution2.minDistance(word1, word2) << endl;    

    return 0;
}