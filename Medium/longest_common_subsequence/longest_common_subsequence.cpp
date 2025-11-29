#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lcs = 0;
        int i = 0, j = 0;
        int m = text1.size(), n = text2.size();
        while(i < m && j < n){
            if(text1[i] == text2[j]){
                lcs++;
                i++;
                j++;
            } else{
                int temp_j = j;
                bool found = false;
                while(temp_j < n){
                    if(text1[i] == text2[temp_j]){
                        found = true;
                        break;
                    }
                    temp_j++;
                }
                if(!found){
                    i++;
                }
            }
        }
        return lcs;
    }
};

int main(){
    Solution solution1;
    string text1 = "abcde";
    string text2 = "ace";
    int result1 = solution1.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence of \"" << text1 << "\" and \"" << text2 << "\" is: " << result1 << endl;

    text1 = "abc";
    text2 = "abc";
    int result2 = solution1.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence of \"" << text1 << "\" and \"" << text2 << "\" is: " << result2 << endl;

    text1 = "abc";
    text2 = "def";
    int result3 = solution1.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence of \"" << text1 << "\" and \"" << text2 << "\" is: " << result3 << endl;
    return 0;

}