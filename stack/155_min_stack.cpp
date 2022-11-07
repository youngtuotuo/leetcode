#include <iostream>
#include <stack>
using namespace std;

/* Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

https://leetcode.com/problems/min-stack/description/
O(1), O(n) */

class MinStack {
  public:
    MinStack() {}
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            stk.push({val, min(val, stk.top().second)});
        }
    }

    void pop() { stk.pop(); }

    int top() { return stk.top().first; }

    int getMin() { return stk.top().second; }

  private:
    stack<pair<int, int>> stk;
};

int main(int argc, char *argv[]) {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}
