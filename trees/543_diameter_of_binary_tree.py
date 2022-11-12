from typing import Optional


"""
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

https://leetcode.com/problems/diameter-of-binary-tree/description/
O(n), O(n)
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right=right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        dia = 0

        def dfs(root):
            nonlocal dia
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            dia = max(dia, left + right)
            return 1 + max(left, right)

        dfs(root)
        return dia


if __name__ == "__main__":
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print(Solution().diameterOfBinaryTree(root))
