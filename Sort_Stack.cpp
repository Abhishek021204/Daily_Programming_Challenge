#include <iostream>
#include <stack>

using namespace std;

void stackInsert(stack<int> &stk, int x) {
  if (stk.empty() || x <= stk.top())
    stk.push(x);
  else {
    int temp = stk.top();
    stk.pop();
    stackInsert(stk, x);
    stk.push(temp);
  }
}
void stackSort(stack<int> &stk) {
  if (stk.size() <= 1)
    return;
  int temp = stk.top();
  stk.pop();
  stackSort(stk);
  stackInsert(stk, temp);
}
int main() {
  stack<int> stk({3, 1, 4, 2});
  stackSort(stk);
  while (!stk.empty()) {
    cout << stk.top() << " ";
    stk.pop();
  }
}
