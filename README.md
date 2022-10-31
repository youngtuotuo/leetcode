# Leetcode based on [NeetCode](https://neetcode.io/practice)
All code are runnable, not only contains the Solution class.

# Useful code snippet for some data structure
## Singly Linked List

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})->{self.next.__repr__()}"

node = ListNode(1, ListNode(2, ListNode(3)))
print(node)

```
```
ListNode(1)->ListNode(2)->ListNode(3)->None
```

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

ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3)));
head->print();
```
```
1 -> 2 -> 3 -> NULL
```

# Binary Tree

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def printBT(prefix: str, node: TreeNode, isRoot: bool, isLeft: bool):
    if node:
        res = prefix
        res += "root " if isRoot else "left " if isLeft else "right "
        res += str(node.val)
        print(res)
        printBT(prefix + "    ", node.left, False, True)
        printBT(prefix + "    ", node.right, False, False)

root = TreeNode(
    4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9))
)
printBT("", root, True, False)
```

```
root 4
    left 2
        left 1
        right 3
    right 7
        left 6
        right 9
```

```cpp
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

};

void printBT(const string& prefix, const TreeNode* node, bool isRoot, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isRoot ? "root ": (isLeft ? "left " : "right "));

    // print the value of the node
    cout << node->val << endl;

    // enter the next tree level
    printBT(prefix + "    ", node->left, false, true);
    printBT(prefix + "    ", node->right, false, false);

  }
}

void printBT(const TreeNode* node) {
  printBT("", node, true, false);
}

TreeNode *root =
  new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
               new TreeNode(7, new TreeNode(6), new TreeNode(9)));
printBT(root);
```
```
root 4
    left 2
        left 1
        right 3
    right 7
        left 6
        right 9
```
