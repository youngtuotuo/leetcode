#include <iostream>
using namespace std;

/* Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
https://leetcode.com/problems/palindrome-linked-list/description/
O(n), O(1) */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
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
    bool isPlaindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* middle = getMiddle(head);
        ListNode* second_start = reverse(middle->next);
        bool res = true;
        ListNode* first = head;
        ListNode* second = second_start;
        while (res == true && second != nullptr) {
            if (first->val != second->val) {
                res = false;
            }
            first = first->next;
            second = second->next;
        }
        middle->next = reverse(second_start);
        return res;
        

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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(1)));
    head->print();
    cout << Solution().isPlaindrome(head) << endl;
    return 0;
}

