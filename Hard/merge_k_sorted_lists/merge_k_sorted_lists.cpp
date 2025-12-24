#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if(l1){
            current->next = l1;
        }
        if(l2){
            current->next = l2;
        }
        return dummy.next;
    }

    // Merge k lists using divide and conquer
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }

        int interval = 1;
        int n = lists.size();

        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};

ListNode* vectorToList(const vector<int>& nums) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (size_t i = 0; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return dummy.next;
}

// Print linked list using index-based traversal
void printList(ListNode* head) {
    cout << "[";
    ListNode* current = head;
    while (current) {
        cout << current->val;
        current = current->next;
        if (current){
            cout << ",";
        }
    }
    cout << "]" << endl;
}


//Example usage:
int main(){
    Solution solution;

    // Example 1
    vector<vector<int>> input = {{1,4,5}, {1,3,4}, {2,6}};
    vector<ListNode*> lists;
    for (size_t i = 0; i < input.size(); i++) {
        lists.push_back(vectorToList(input[i]));
    }

    ListNode* merged = solution.mergeKLists(lists);
    cout << "Merged list for input [[1,4,5],[1,3,4],[2,6]]: ";
    printList(merged);  // Expected: [1,1,2,3,4,4,5,6]

    // Example 2: empty input
    vector<ListNode*> emptyLists;
    merged = solution.mergeKLists(emptyLists);
    cout << "Merged list for input []: ";
    printList(merged);  // Expected: []

    // Example 3: list with empty lists
    vector<vector<int>> input2 = {{}};
    vector<ListNode*> lists2;
    for (size_t i = 0; i < input2.size(); i++) {
        lists2.push_back(vectorToList(input2[i]));
    }
    merged = solution.mergeKLists(lists2);
    cout << "Merged [[]]: ";
    printList(merged);

    return 0;
}