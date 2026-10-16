#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummyHead = new ListNode(0);
            ListNode* current = dummyHead;
            int carry = 0;

            while (l1 != nullptr || l2 != nullptr || carry != 0) {
                int sum = carry;
                if (l1 != nullptr) {
                    sum = sum + l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    sum = sum + l2->val;
                    l2 = l2->next;
                }
                carry = sum / 10;
                current->next = new ListNode(sum % 10);
                current = current->next;
            }
            return dummyHead->next;
        }
};

// Example usage:
int main() {
    Solution solution1;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = solution1.addTwoNumbers(l1, l2);
    vector<int> output;
    while (result) {
        output.push_back(result->val);
        result = result->next;
    }
    cout << "For the input (2 -> 4 -> 3) + (5 -> 6 -> 4), the output is: (" << output[0];
    for (size_t i = 1; i < output.size(); ++i) {
        cout << " -> " << output[i];
    }
    cout << ")" << endl;  // Output: (7->0->8)

    cout << endl;

    Solution solution2;
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(0);
    result = solution2.addTwoNumbers(l3, l4);
    output.clear();
    while (result) {
        output.push_back(result->val);
        result = result->next;
    }
    cout << "For the input (0) + (0), the output is: (" << output[0] << ")" << endl;  // Output: (0)

    cout << endl;

    Solution solution3;
    ListNode* l5 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l6 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    result = solution3.addTwoNumbers(l5, l6);
    output.clear();
    while (result) {
        output.push_back(result->val);
        result = result->next;
    }
    cout << "For the input (9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9) + (9 -> 9 -> 9 -> 9), the output is: (" << output[0];
    for (size_t i = 1; i < output.size(); ++i) {
        cout << " -> " << output[i];
    }
    cout << ")" << endl;  // Output: (8->9->9->9->0->0->0)

    return 0;
}