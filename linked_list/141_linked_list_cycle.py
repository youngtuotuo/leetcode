from typing import Optional


"""
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

https://leetcode.com/problems/linked-list-cycle/

O(n), O(1)
"""

class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        while (fast and fast.next):
            fast = fast.next.next
            slow = slow.next
            if (slow == fast):
                return True
        return False
        


if __name__ == "__main__":
    head = ListNode(3)
    node = ListNode(2, ListNode(0))
    tail = ListNode(4)

    head.next = node
    node.next.next = tail
    tail.next = node
