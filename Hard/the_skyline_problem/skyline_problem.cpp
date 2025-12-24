#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events; // (x, height)
        int n = buildings.size();

        // Use index-based iteration instead of 'auto &b'
        for (int i = 0; i < n; i++) {
            int L = buildings[i][0];
            int R = buildings[i][1];
            int H = buildings[i][2];

            events.push_back({L, -H}); // start event, negative height
            events.push_back({R, H});  // end event, positive height
        }

        // Sort by x; start (-height) before end (+height) if tied
        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0); // ground level

        vector<vector<int>> result;
        int prev_max = 0;

        for (int i = 0; i < events.size(); i++) {
            int x = events[i].first;
            int h = events[i].second;

            if (h < 0) {
                // Start of building
                heights.insert(-h);
            } else {
                // End of building
                heights.erase(heights.find(h));
            }

            int current_max = *heights.rbegin();
            if (current_max != prev_max) {
                result.push_back({x, current_max});
                prev_max = current_max;
            }
        }

        return result;
    }
};

// Example usage:
int main(){
    Solution sol;
    vector<vector<int>> buildings1 = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyline1 = sol.getSkyline(buildings1);

    cout << "Skyline for buildings1: {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}: ";
    for (int i = 0; i < skyline1.size(); i++) {
        cout << "[" << skyline1[i][0] << "," << skyline1[i][1] << "]";
        if (i != skyline1.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;

    vector<vector<int>> buildings2 = {{0,2,3},{2,5,3}};
    vector<vector<int>> skyline2 = sol.getSkyline(buildings2);
    cout << "Skyline for buildings2: {0,2,3},{2,5,3} ";
    for (int i = 0; i < skyline2.size(); i++) {
        cout << "[" << skyline2[i][0] << "," << skyline2[i][1] << "]";
        if (i != skyline2.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}