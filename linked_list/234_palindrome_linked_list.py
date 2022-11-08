from typing import Optional


"""
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
https://leetcode.com/problems/palindrome-linked-list/description/
O(n), O(1)
"""


class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return True

        middle = self.getMiddle(head)
        second_start = self.reverse_list(middle.next)

        res = True
        first = head
        second = second_start
        while res and second != None:
            if first.val != second.val:
                res = False
            first = first.next
            second = second.next

        middle.next = self.reverse_list(second_start)
        return res

    def getMiddle(self, head):
        fast = head
        slow = head
        while fast.next != None and fast.next.next != None:
            fast = fast.next.next
            slow = slow.next
        return slow

    def reverse_list(self, head):
        prev = None
        curr = head
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp

        return prev


if __name__ == "__main__":
    head = ListNode(1, ListNode(2))
    print(Solution().isPalindrome(head))
