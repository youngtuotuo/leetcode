#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int iterDFS(TreeNode *root) {
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        int res = 0;
        while (!s.empty()) {
            TreeNode *node = s.top().first;
            int depth = s.top().second;
            s.pop();
            if (node != nullptr) {
                res = max(res, depth);
                s.push({node->left, depth + 1});
                s.push({node->right, depth + 1});
            }
        }
        return res;
    }

    int iterBFS(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                if (node->left != nullptr) {
                    q.push_back(node->left);
                }
                if (node->right != nullptr) {
                    q.push_back(node->right);
                }
            }
            level++;
        }
        return level;
    }
};

int main(int argc, char *argv[]) {
    // [0,2,4,1,null,3,-1,5,1,null,6,null,8]
    TreeNode *root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << Solution().iterBFS(root) << endl;
    return 0;
}
