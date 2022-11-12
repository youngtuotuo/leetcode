#include <iostream>
using namespace std;

/* Given a binary tree, determine if it is height-balanced.
https://leetcode.com/problems/balanced-binary-tree/description/
O(n), O(n) */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isBalanced(TreeNode *root) { return dfs(root).first; }

  private:
    pair<bool, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);
        bool balanced =
            (left.first && right.first && abs(left.second - right.second) <= 1);
        return {balanced, 1 + max(left.second, right.second)};
    }
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

int main(int argc, char *argv[]) {
    TreeNode *root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    printBT(root);
    cout << Solution().isBalanced(root) << endl;
    return 0;
}
