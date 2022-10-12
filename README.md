# Leetcode practice based on [NeetCode](https://neetcode.io/practice)
# All code are runnable, not only contains the Solution class.

# Useful code snippet for some data structure
Add *__repr__*

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})->{self.next.__repr__()}"
```

then you can define singly linked list and display it

```python
node = ListNode(1, ListNode(2, ListNode(3)))
print(node)

```
```
ListNode(1)->ListNode(2)->ListNode(3)->None
```


In C++ you can do this

```cpp
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
```
then you can

```cpp
ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3)));
head->print();
```
```
1 -> 2 -> 3 -> NULL
```
