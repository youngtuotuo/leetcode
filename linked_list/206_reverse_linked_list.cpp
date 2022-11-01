#include <cstddef>
#include <iostream>
using namespace std;

/*
Given the head of a singly linked list, reverse the list, and return the
reversed list. https://leetcode.com/problems/reverse-linked-list/
*/

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
}

class Solution {
  public:
    // O(n), O(1)
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = curr->next;

        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    // O(n), O(n)
    ListNode *recursive(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *newHead = head;
        if (head->next != NULL) {
            newHead = recursive(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return newHead;
    }
};

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3)));
    head->print();
    // Solution().reverseList(head)->print();
    Solution().recursive(head)->print();
    return 0;
}
