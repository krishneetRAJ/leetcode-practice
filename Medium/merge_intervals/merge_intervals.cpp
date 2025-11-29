#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals){
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);
            for(int i = 1; i < intervals.size(); i++){
                if(merged.back()[1] >= intervals[i][0]){
                    merged.back()[1] = max(merged.back()[1], intervals[i][1]);
                }else{
                    merged.push_back(intervals[i]);
                }
            }
            return merged;
        }
};

// Example usage:
int main(){
    Solution solution;
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result1 = solution.merge(intervals1);
    cout << "For the input {{1,3},{2,6},{8,10},{15,18}}, the output is: {";
    for(int i = 0; i < result1.size(); i++){
        cout << "{" << result1[i][0] << "," << result1[i][1] << "}";
        if(i != result1.size() - 1){
            cout << ",";
        }
    }
    cout << "}" << endl;

    Solution solution2;
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    vector<vector<int>> result2 = solution2.merge(intervals2);
    cout << "For the input {{1,4},{4,5}}, the output is: {";
    for(int i = 0; i < result2.size(); i++){
        cout << "{" << result2[i][0] << "," << result2[i][1] << "}";
        if(i != result2.size() - 1){
            cout << ",";
        }
    }
    cout << "}" << endl;

    Solution solution3;
    vector<vector<int>> intervals3 = {{1,4},{2,3}};
    vector<vector<int>> result3 = solution3.merge(intervals3);
    cout << "For the input {{1,4},{2,3}}, the output is: {";
    for(int i = 0; i < result3.size(); i++){
        cout << "{" << result3[i][0] << "," << result3[i][1] << "}";
        if(i != result3.size() - 1){
            cout << ",";
        }
    }
    cout << "}" << endl;
    return 0;
}