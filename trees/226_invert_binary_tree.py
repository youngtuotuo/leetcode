from typing import Optional

"""
Given the root of a binary tree, invert the tree, and return its root.
https://leetcode.com/problems/invert-binary-tree/
O(n), O(n)
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root


if __name__ == "__main__":
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
