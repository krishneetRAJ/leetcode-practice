#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr) {
                return nullptr;
            }

            ListNode* current = head;

            while (current != nullptr && current->next != nullptr) {
                if (current->val == current->next->val) {
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp; 
                } else {
                    current = current->next;
                }
            }

            return head;
        }
};

// Example usage:
int main() {
    Solution solution1;
    ListNode* head1 = new ListNode(1, new ListNode(1, new ListNode(2)));
    ListNode* result1 = solution1.deleteDuplicates(head1);
    cout << "Testing Remove Duplicates from Sorted List: " << endl;
    cout << "Input: [1, 1, 2]" << endl;
    cout << "Output: [";
    while (result1) {
        cout << result1->val;
        if (result1->next) {
            cout << ", ";
        }
        result1 = result1->next;
    }
    cout << "]" << endl;

    Solution solution2;
    ListNode* head2 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    ListNode* result2 = solution2.deleteDuplicates(head2);
    cout << "" << endl;
    cout << "Input: [1, 1, 2, 3, 3]" << endl;
    cout << "Output: [";
    while (result2) {
        cout << result2->val;
        if (result2->next) {
            cout << ", ";
        }
        result2 = result2->next;    
    }
    cout << "]" << endl;
    return 0;
}
