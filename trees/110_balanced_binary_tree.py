from typing import Optional

"""
Given a binary tree, determine if it is height-balanced.
https://leetcode.com/problems/balanced-binary-tree/description/
O(n), O(n)
"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root):
            if not root:
                return [True, 0]
            left = dfs(root.left)
            right = dfs(root.right)
            balanced = left[0] and right[0] and abs(left[1] - right[1]) <= 1
            return [balanced, 1 + max(left[1], right[1])]

        return dfs(root)[0]


if __name__ == "__main__":

    def printBT(prefix: str, node: TreeNode, isRoot: bool, isLeft: bool):
        if node:
            res = prefix
            res += "root " if isRoot else "left " if isLeft else "right "
            res += str(node.val)
            print(res)
            printBT(prefix + "    ", node.left, False, True)
            printBT(prefix + "    ", node.right, False, False)

    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    printBT("", node=root, isRoot=True, isLeft=False)
    print(Solution().isBalanced(root))
