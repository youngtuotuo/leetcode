#include <cstddef>
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  void Print_list();
};

void ListNode::Print_list() {
  if (next == nullptr) {
    cout << val << " -> NULL " << endl;
  } else {
    ListNode *current = next;
    cout << val << " -> ";
    while (current != nullptr) {
      cout << current -> val << " -> ";
      current = current -> next;
    }
    cout << "NULL" << endl;
  }
}

class Solution {
  // recursive solution
public:
  ListNode *mergeTwoListsRecur(ListNode *list1, ListNode *list2) {
    if (!list1)
    {
      return list2;
    }
    else if (!list2)
    {
      return list1;
    }

    if (list1 -> val <= list2 -> val)
    {
      list1 -> next = mergeTwoListsRecur(list1 -> next, list2);
      return list1;
    } else {
      list2 -> next = mergeTwoListsRecur(list1, list2 -> next);
      return list2;
    }
  }
  ListNode *mergeTwoListsIter(ListNode *list1, ListNode *list2) {
    if (!list1)
    {
      return list2;
    }
    else if (!list2)
    {
      return list1;
    }

    ListNode *dummy = new ListNode{};
    ListNode *curr = dummy;
    while (list1 && list2) {
      if (list1 -> val <= list2 -> val) {
        curr -> next = list1;
        list1 = list1 -> next;
      } else {
        curr -> next = list2;
        list2 = list2 -> next;
      }
      curr = curr -> next;
    }
    if (list1 != nullptr) {
      curr -> next = list1;
    }
    else if (list2 != nullptr)
    {
      curr -> next = list2;
    }
    return dummy -> next;
  }

};

int main() {
  ListNode list1{1, new ListNode{2, new ListNode{4}}};
  ListNode list2{1, new ListNode{3, new ListNode{4}}};
  list1.Print_list();
  list2.Print_list();
  Solution().mergeTwoListsIter(&list1, &list2)->Print_list();
  return 0;
}
