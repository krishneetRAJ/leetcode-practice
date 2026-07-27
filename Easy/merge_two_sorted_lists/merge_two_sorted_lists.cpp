#include <iostream>
#include <vector>
using namespace std;

/*
* Definition for singly linked list. */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]";
        return;
    }

    cout << "[";

    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << ", ";
        }

        head = head->next;
    }

    cout << "]";
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test 1: [1,2,4] and [1,3,4]
    ListNode* list1 =
        new ListNode(1, new ListNode(2, new ListNode(4)));

    ListNode* list2 =
        new ListNode(1, new ListNode(3, new ListNode(4)));

    cout << "Test case 1" << endl;
    cout << "List 1: ";
    printList(list1);
    cout << endl;

    cout << "List 2: ";
    printList(list2);
    cout << endl;

    ListNode* mergedList1 = solution.mergeTwoLists(list1, list2);

    cout << "Merged: ";
    printList(mergedList1);
    cout << endl << endl;

    deleteList(mergedList1);


    // Test 2: [] and []
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;

    cout << "Test case 2" << endl;
    cout << "List 1: ";
    printList(list3);
    cout << endl;

    cout << "List 2: ";
    printList(list4);
    cout << endl;

    ListNode* mergedList2 = solution.mergeTwoLists(list3, list4);

    cout << "Merged: ";
    printList(mergedList2);
    cout << endl << endl;


    // Test 3: [] and [0]
    ListNode* list5 = nullptr;
    ListNode* list6 = new ListNode(0);

    cout << "Test case 3" << endl;
    cout << "List 1: ";
    printList(list5);
    cout << endl;

    cout << "List 2: ";
    printList(list6);
    cout << endl;

    ListNode* mergedList3 = solution.mergeTwoLists(list5, list6);

    cout << "Merged: ";
    printList(mergedList3);
    cout << endl;

    deleteList(mergedList3);

    return 0;
}