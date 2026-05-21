#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class MedianFinder {
    public:
        priority_queue<int> small; //Max heap
        priority_queue<int, vector<int>, greater<int>> large; 

        MedianFinder() {

        }

        void addNum(int num) {
            small.push(num);

            if (!large.empty() && small.top() > large.top()) {
                large.push(small.top());
                small.pop();
            }

            if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            }

            if (large.size() > small.size()) {
                small.push(large.top());
                large.pop();
            }
        }
    
        double findMedian() {
            if (small.size() > large.size()) {
                return small.top();
            }

        return (small.top() + large.top()) / 2.0;
    }
};

//Example usage:
int main() {
    MedianFinder medianFinder;

    cout << fixed << setprecision(5); 
    cout << "Testing Find Median from Data Stream: " << endl;
    cout << "With the following input: [null, 1, 2, null, 3, null]" << endl;
    cout << "";
    cout << "Output: " << endl;
    cout << "[";
    cout << "null,";  

    medianFinder.addNum(1);
    cout << "null,";   

    medianFinder.addNum(2);
    cout << "null,";

    cout << medianFinder.findMedian() << ",";

    medianFinder.addNum(3);
    cout << "null,";  

    cout << medianFinder.findMedian();

    cout << "]" << endl;

    return 0;
}