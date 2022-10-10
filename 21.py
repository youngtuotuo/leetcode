from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"{self.val} -> {self.next.__repr__()}"


class Solution:
    def mergeTwoListsRercur(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        elif not list2:
            return list1

        if (list1.val <= list2.val):
            list1.next = self.mergeTwoListsRercur(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoListsRercur(list1, list2.next)
            return list2

    def mergeTwoListsIter(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]: 
        dummy = curr = ListNode()
        while (list1) and (list2):
            if list1.val <= list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        curr.next = (list1) or (list2)
        return dummy.next




if __name__ == "__main__":
    list1 = ListNode(1, ListNode(2, ListNode(4)))
    list2 = ListNode(1, ListNode(3, ListNode(4)))
    print(Solution().mergeTwoListsIter(list1, list2))
