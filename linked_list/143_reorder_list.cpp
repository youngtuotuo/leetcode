#include <iostream>
using namespace std;

/* You are given the head of a singly linked-list. The list can be represented
as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be
changed.

https://leetcode.com/problems/reorder-list/
O(n), O(1) */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print();
};

void ListNode::print() {
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
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* first_start = head;
        ListNode* middle = getMiddle(head);
        ListNode* second_start = reverse(middle->next);
        middle->next = nullptr;
        while (first_start != nullptr && second_start != nullptr) {
            ListNode* tmp_first = first_start->next;
            ListNode* tmp_second = second_start->next;
            first_start->next = second_start;
            second_start->next = tmp_first;

            first_start = tmp_first;
            second_start = tmp_second;
        }

    }

    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};


int main (int argc, char *argv[])
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    head->print();
    Solution().reorderList(head);
    head->print();
    return 0;
}
