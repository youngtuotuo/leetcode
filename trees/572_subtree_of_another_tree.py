from typing import Optional

"""
Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root with the same structure and node values of subRoot and false
otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and
all of this node's descendants. The tree tree could also be considered as a
subtree of itself.
https://leetcode.com/problems/subtree-of-another-tree/

O(mn), O(m)
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False

        if self.same(root, subRoot):
            return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def same(self, root, subRoot):
        if not root and not subRoot:
            return True
        elif not root or not subRoot:
            return False
        elif root.val != subRoot.val:
            return False

        return self.same(root.left, subRoot.left) and self.same(
            root.right, subRoot.right
        )


if __name__ == "__main__":
    root = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2)), TreeNode(5))
    subRoot = TreeNode(4, TreeNode(1), TreeNode(2))
    print(Solution().isSubtree(root, subRoot))
