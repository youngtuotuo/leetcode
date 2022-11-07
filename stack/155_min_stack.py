"""
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

https://leetcode.com/problems/min-stack/description/
O(1), O(n)
"""


class MinStack:
    def __init__(self) -> None:
        self._stack = []

    def push(self, val: int) -> None:
        if not self._stack:
            self._stack.append((val, val))
        else:
            self._stack.append((val, min(self._stack[-1][-1], val)))

    def pop(self) -> None:
        del self._stack[-1]

    def top(self) -> int:
        return self._stack[-1][0]

    def getMin(self) -> int:
        return self._stack[-1][-1]


if __name__ == "__main__":
    obj = MinStack()
    obj.push(-2)
    obj.push(0)
    obj.push(-3)
    print(obj.getMin())
    obj.pop()
    print(obj.top())
    print(obj.getMin())
