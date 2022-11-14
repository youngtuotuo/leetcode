#include <iostream>
using namespace std;

/* Given the roots of two binary trees root and subRoot, return true if there is
a subtree of root with the same structure and node values of subRoot and false
otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and
all of this node's descendants. The tree tree could also be considered as a
subtree of itself.
https://leetcode.com/problems/subtree-of-another-tree/

O(mn), O(m) */

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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (same(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
    bool same(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr || subRoot == nullptr) {
            return false;
        } else if (root->val != subRoot->val) {
            return false;
        }
        return same(root->left, subRoot->left) &&
               same(root->right, subRoot->right);
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(
        3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    TreeNode *subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << Solution().isSubtree(root, subRoot) << endl;
    return 0;
}
