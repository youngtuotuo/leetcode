#include <iostream>
using namespace std;

/* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    int diameterOfBinaryTree(TreeNode *root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }

private:
    int dfs(TreeNode* root, int& dia) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, dia);
        int right = dfs(root->right, dia);
        dia = max(dia, left+right);
        return 1 + max(left, right); // height
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(
        1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}
