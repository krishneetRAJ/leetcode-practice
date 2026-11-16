#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> count;
            for(int i = 0; i < arr.size(); i++) {
                count[arr[i]]++;
            }
            unordered_set<int> occurrences;
            for(int i = 0; i < arr.size(); i++) {
                occurrences.insert(count[arr[i]]);
            }
            return occurrences.size() == count.size();
        }
};

// Example usage:
int main() {
    Solution solution1;
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    bool result1 = solution1.uniqueOccurrences(arr1);
    cout << "For the input [1, 2, 2, 1, 1, 3], the result is: " << boolalpha << result1 << endl;

    Solution solution2;
    vector<int> arr2 = {1, 2};
    bool result2 = solution2.uniqueOccurrences(arr2);
    cout << "For the input [1, 2], the result is: " << boolalpha << result2 << endl;

    Solution solution3;
    vector<int> arr3 = {-3,0,1,-3,1,1,-3,10,0};
    bool result3 = solution3.uniqueOccurrences(arr3);
    cout << "For the input [-3,0,1,-3,1,1,-3,10,0], the result is: " << boolalpha << result3 << endl;
    return 0;
};