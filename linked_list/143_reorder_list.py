from typing import Optional


"""
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

https://leetcode.com/problems/reorder-list/
O(n), O(1)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})->{self.next.__repr__()}"


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        first_start = head
        # get half and reverse it
        middle = self.getMiddle(head)
        second_start = self.reverse(middle.next)
        middle.next = None

        # merge two half
        while first_start and second_start:
            tmp_first = first_start.next
            tmp_second = second_start.next

            first_start.next = second_start
            second_start.next = tmp_first

            first_start = tmp_first
            second_start = tmp_second

    def getMiddle(self, head):
        fast = head
        slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def reverse(self, head):
        prev = None
        curr = head
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev


if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    print(head)
    Solution().reorderList(head)
    print(head)

