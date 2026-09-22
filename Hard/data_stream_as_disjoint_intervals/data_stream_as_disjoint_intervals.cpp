#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SummaryRanges {
    public:
        vector<vector<int>> intervals;

        SummaryRanges() {

        }

    void addNum(int value) {
        vector<vector<int>> newIntervals;
        int start = value;
        int end = value;

        for (vector<int>& interval : intervals) {

            // Current interval comes before the new value
            if (interval[1] < start - 1) {
                newIntervals.push_back(interval);
            }
            // Current interval comes after the new value
            else if (interval[0] > end + 1) {
                newIntervals.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }

            // Intervals overlap or touch
            else {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }

        newIntervals.push_back({start, end});
        intervals = newIntervals;
    }

    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

// Example usage:
int main() {
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    cout << "Intervals after adding 1: ";
    for (const auto& interval : summaryRanges.getIntervals()) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    summaryRanges.addNum(3);
    cout << "Intervals after adding 3: ";
    for (const auto& interval : summaryRanges.getIntervals()) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    summaryRanges.addNum(7);
    cout << "Intervals after adding 7: ";
    for (const auto& interval : summaryRanges.getIntervals()) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    summaryRanges.addNum(2);
    cout << "Intervals after adding 2: ";
    for (const auto& interval : summaryRanges.getIntervals()) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;   

    summaryRanges.addNum(6);
    cout << "Intervals after adding 6: ";
    for (const auto& interval : summaryRanges.getIntervals()) {     
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;   

    return 0;
}