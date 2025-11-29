#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
    public:
        int maxPoints(vector<vector<int>> &points){
            int n = points.size();
            if(n <= 2){
                return n;
            }
            int maxPoints = 2;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    int count = 2;
                    int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                    for(int k = 0; k < n; k++){
                        if(k==i || k==j){
                            continue;
                        }
                        int x = points[k][0], y = points[k][1];
                        if((y2 - y1) * (x - x1) == (y - y1) * (x2 - x1)){
                            count++;
                        }
                    }
                    if(count > maxPoints){
                        maxPoints = count;
                    }
                }
            }
        return maxPoints;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> pts1 = {{1,1},{2,2},{3,3}};
    vector<vector<int>> pts2 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};

    cout << "For points {{1,1},{2,2},{3,3}}, max points on a line: " << sol.maxPoints(pts1) << endl;
    cout << "For points {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}, max points on a line: " << sol.maxPoints(pts2) << endl;
    return 0;
}