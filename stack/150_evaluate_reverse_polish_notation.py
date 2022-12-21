from typing import List

"""
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another
expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the
expression would always evaluate to a result, and there will not be any
division by zero operation.

https://leetcode.com/problems/evaluate-reverse-polish-notation/
"""


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                stack.append(stack.pop() + stack.pop())
            elif token == "-":
                a, b = stack.pop(), stack.pop()
                stack.append(b - a)
            elif token == "*":
                stack.append(stack.pop() * stack.pop())
            elif token == "/":
                a, b = stack.pop(), stack.pop()
                stack.append(int(b / a))
            else:
                stack.append(int(token))
        return stack.pop()


if __name__ == "__main__":
    tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    # tokens = ["4", "3", "-"]
    # tokens = ["4", "-2", "/", "2", "-3", "-", "-"]
    print(Solution().evalRPN(tokens))
