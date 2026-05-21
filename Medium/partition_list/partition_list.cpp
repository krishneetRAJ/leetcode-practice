#include <vector>
#include <algorithm>
#include <iostream>
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
        ListNode* partition(ListNode* head, int x) {
            if(!head) {
                return nullptr;
            }
            ListNode* lessHead = new ListNode(0); 
            ListNode* greaterHead = new ListNode(0); 
            ListNode* less = lessHead;
            ListNode* greater = greaterHead;

            while(head) {
                if(head->val < x) {
                    less->next = head;
                    less = less->next;
                } else {
                    greater->next = head;
                    greater = greater->next;
                }
                head = head->next;
            }
            greater->next = nullptr; 
            less->next = greaterHead->next; 
            return lessHead->next; //Return the head of the new list
        }
};

//Example usage:
int main() {
    Solution solution1;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);
    int x1 = 3;

    ListNode* result1 = solution1.partition(head1, x1);
    cout << "Testing Partition List: " << endl;
    cout << "Input: head = [1, 4, 3, 2, 5, 2], x = 3" << endl;
    cout << "Output: [";
    while(result1) {
        cout << result1->val;
        if(result1->next) {
            cout << ", ";
        }
        result1 = result1->next;
    }
    cout << "]" << endl;

    Solution solution2;
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    int x2 = 2;

    ListNode* result2 = solution2.partition(head2, x2);
    cout << "" << endl;
    cout << "Input: head = [2, 1], x = 2" << endl;
    cout << "Output: [";
    while(result2) {
        cout << result2->val;
        if(result2->next) {
            cout << ", ";
        }
        result2 = result2->next;
    }
    cout << "]" << endl;
}
    

