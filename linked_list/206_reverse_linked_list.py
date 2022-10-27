from typing import Optional


"""
Given the head of a singly linked list, reverse the list, and return the reversed list.
https://leetcode.com/problems/reverse-linked-list/
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})->{self.next.__repr__()}"


class Solution:
    # O(n), O(1)
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        return prev

    # O(n), O(n)
    def recursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        newHead = head
        if head.next:
            newHead = self.recursive(head.next)
            head.next.next = head

        head.next = None
        return newHead


if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3)))
    # print(Solution().recursive(head))
    print(Solution().reverseList(head))
