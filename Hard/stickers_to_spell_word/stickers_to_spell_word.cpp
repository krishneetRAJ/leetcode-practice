#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int minStickers(vector<string>& stickers, string target) {
            queue<pair<string, int>> q;
            unordered_set<string> visited;

            q.push({target, 0});
            visited.insert(target);
            while(!q.empty()) {
                string remaining = q.front().first;
                int count = q.front().second;
                q.pop();

                if(remaining.empty()) {
                    return count;
                }
                for(int i = 0; i < stickers.size(); i++) {
                    unordered_map<char, int> available;
                    for(int j = 0; j < stickers[i].size(); j++) {
                        available[stickers[i][j]]++;
                    }
                    string newRemaining = "";
                    for(int j = 0; j < remaining.size(); j++) {
                        char c = remaining[j];
                        if(available[c] > 0) {
                            available[c]--;
                        } else {
                            newRemaining += c;
                        }
                    }
                    if(newRemaining.empty()) {
                        return count + 1;
                    }
                    if(visited.count(newRemaining) == 0) {
                        visited.insert(newRemaining);
                        q.push({newRemaining, count + 1});
                    }
                }
            }
            return -1;
        }
};

// Example usage:
int main() {
    Solution solution1;
    vector<string> stickers1 = {"with", "example", "science"};
    string target1 = "thehat";
    int result1 = solution1.minStickers(stickers1, target1);
    cout << "Testing Stickers to Spell Word: " << endl;
    cout << "Input: stickers = [\"with\", \"example\", \"science\"], target = \"thehat\"" << endl;
    cout << "Output: " << result1 << endl;

    Solution solution2;
    vector<string> stickers2 = {"notice", "possible"};
    string target2 = "basicbasic";
    int result2 = solution2.minStickers(stickers2, target2);
    cout << "" << endl;
    cout << "Input: stickers = [\"notice\", \"possible\"], target = \"basicbasic\"" << endl;
    cout << "Output: " << result2 << endl;

    return 0;
};