#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> result;
            int i = 0;
            int n = words.size();

            while (i < n) {
                vector<string> line;
                int length = 0;

                // collect words for the line
                while (i < n && length + words[i].size() + line.size() <= maxWidth) {
                    line.push_back(words[i]);
                    length += words[i].size();
                    i++;
                }

                string s;

                // last line OR single word → left justify
                if (i == n || line.size() == 1) {
                    for (int j = 0; j < line.size(); j++) {
                        if (j > 0) {
                            s += " ";
                        }
                        s += line[j];
                    }

                    // pad remaining spaces
                    int remaining = maxWidth - s.size();
                    for (int k = 0; k < remaining; k++) {
                        s += " ";
                    }
                }
                else {
                    int spaces = maxWidth - length;
                    int gaps = line.size() - 1;
                    int even = spaces / gaps;
                    int extra = spaces % gaps;

                    for (int j = 0; j < line.size(); j++) {
                        s += line[j];

                        if (j < gaps) {
                            int count = even;
                            if (j < extra) {
                                count += 1;
                            }

                            for (int k = 0; k < count; k++) {
                                s += " ";
                            }
                        }
                    }
                }
                result.push_back(s);
            }

            return result;
    }
};

int main() {
    Solution solution1;
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution1.fullJustify(words1, maxWidth1);
    cout << "Testing Text Justification: " << endl;
    cout << "Input: words = [\"This\", \"is\", \"an\", \"example\", \"of\", \"text\", \"justification.\"], maxWidth = 16" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    Solution solution2;
    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution2.fullJustify(words2, maxWidth2);
    cout << "" << endl;
    cout << "Input: words = [\"What\",\"must\",\"be\",\"acknowledgment\",\"shall\",\"be\"], maxWidth = 16" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    Solution solution3;
    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","what","we","do","with","what","we","understand."};
    int maxWidth3 = 20;
    vector<string> result3 = solution3.fullJustify(words3, maxWidth3);
    cout << "" << endl;
    cout << "Input: words = [\"Science\",\"is\",\"what\",\"we\",\"understand\",\"well\",\"enough\",\"to\",\"explain\",\"to\",\"a\",\"computer.\",\"Art\",\"is\",\"what\",\"we\",\"do\",\"with\",\"what\",\"we\",\"understand.\"], maxWidth = 20" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}