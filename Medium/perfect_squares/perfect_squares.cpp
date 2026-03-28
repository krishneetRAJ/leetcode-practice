#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int numSquares(int n) {
            vector<int> a(n+1, n);
            a[0] = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; (j*j) <= i; j++){
                    if(a[i] > a[i-(j*j)] + 1){
                        a[i] = a[i-(j*j)] + 1;
                    }
                }
            }
            return a[n];
    }
};

//Example usage:
int main(){
    Solution solution1;
    int n1 = 12;
    int result1 = solution1.numSquares(n1);
    cout << "For the input " << n1 << ", the output is: " << result1 << endl;

    Solution solution2;
    int n2 = 13;
    int result2 = solution2.numSquares(n2);
    cout << "For the input " << n2 << ", the output is: " << result2 << endl;
    return 0;
};