#include <iostream>
using namespace std;



/* Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

https://leetcode.com/problems/linked-list-cycle/

O(n), O(1) */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;
      while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          return true;
        }
      }
      return false;
    }
};

int main (int argc, char *argv[])
{
  ListNode* head = new ListNode(3);
  ListNode* node = new ListNode(2);
  node->next = new ListNode(0);
  ListNode* tail = new ListNode(4);
  head->next = node;
  node->next->next = tail;
  tail->next = node;
  cout << Solution().hasCycle(head) << endl;
  return 0;
}
