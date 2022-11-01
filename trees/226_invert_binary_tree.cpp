#include <iostream>
using namespace std;

/*
Given the root of a binary tree, invert the tree, and return its root.
https://leetcode.com/problems/invert-binary-tree/
O(n), O(n)
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void printBT(const string &prefix, const TreeNode *node, bool isRoot,
             bool isLeft) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isRoot ? "root " : (isLeft ? "left " : "right "));

        // print the value of the node
        cout << node->val << endl;

        // enter the next tree level
        printBT(prefix + "    ", node->left, false, true);
        printBT(prefix + "    ", node->right, false, false);
    }
}

void printBT(const TreeNode *node) { printBT("", node, true, false); }

class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root =
        new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                     new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    printBT(root);
    TreeNode *ans = Solution().invertTree(root);
    printBT(ans);
    return 0;
}
