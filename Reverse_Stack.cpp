#include <iostream>
#include <stack>

using namespace std;

void insertBottom(stack<int> &stk, int x) {
  if (stk.empty()) {
    stk.push(x);
    return;
  }
  int temp = stk.top();
  stk.pop();
  insertBottom(stk, x);
  stk.push(temp);
}
void reverseStack(stack<int> &stk) {
  if (stk.size() <= 1)
    return;
  int temp = stk.top();
  stk.pop();
  reverseStack(stk);
  insertBottom(stk, temp);
}
int main() {
  stack<int> stk({1, 2, 3, 4});
  // 4 is top
  reverseStack(stk);
  while (!stk.empty()) {
    cout << stk.top() << " ";
    // 1 is top
    stk.pop();
  }
}
