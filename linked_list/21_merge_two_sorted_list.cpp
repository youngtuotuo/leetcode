#include <iostream>
using namespace std;

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

https://leetcode.com/problems/merge-two-sorted-lists/

O(n), O(n)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print() {
        if (next == nullptr) {
            cout << val << " -> NULL" << endl;
        } else {
            ListNode *current = next;
            cout << val << " -> ";
            while (current != nullptr) {
                cout << current->val << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *res = new ListNode();
        ListNode *curr = res;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 != nullptr) {
            curr->next = list1;
        } else if (list2 != nullptr) {
            curr->next = list2;
        }
        return res->next;
    }
};

int main(int argc, char *argv[]) {
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    list1->print();
    list2->print();
    Solution().mergeTwoLists(list1, list2)->print();
    return 0;
}
