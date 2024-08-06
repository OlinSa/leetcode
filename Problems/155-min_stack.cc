#include <assert.h>

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
 public:
  MinStack() { min_stk_.push(INT32_MAX); }

  void push(int val) {
    stk_.push(val);
    min_stk_.push(std::min(val, min_stk_.top()));
  }

  void pop() {
    stk_.pop();
    min_stk_.pop();
  }

  int top() { return stk_.top(); }

  int getMin() { return min_stk_.top(); }

 private:
  stack<int> stk_;
  stack<int> min_stk_;
};

int main(int argc, char* argv[]) {
  MinStack* minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  assert(minStack->getMin() == -3);
  minStack->pop();
  assert(minStack->top() == 0);
  assert(minStack->getMin() == -2);
  return 0;
}