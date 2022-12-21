#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another
expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the
expression would always evaluate to a result, and there will not be any
division by zero operation.

https://leetcode.com/problems/evaluate-reverse-polish-notation/
O(n), O(n)
*/

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }

            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();

            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else if (token == "/") {
                result = num1 / num2;
            }
            stk.push(result);
        }
        return stk.top();
    }
};

int main(int argc, char *argv[]) {
    // vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
    //                          "/",  "*", "17", "+", "5", "+"};
    vector<string> tokens = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    cout << Solution().evalRPN(tokens) << endl;
    return 0;
}
