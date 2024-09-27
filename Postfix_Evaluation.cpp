#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_set>

using namespace std;

int postfix(string &str) {
  stack<int> stk;
  stringstream ss(str);
  string s;
  unordered_set<string> operators{"+", "-", "*", "/", "^"};
  while (ss >> s) {
    if (!operators.count(s)) {
      stk.push(stoi(s));
      continue;
    }
    int temp = stk.top();
    stk.pop();
    if (s == "+")
      stk.top() += temp;
    else if (s == "-")
      stk.top() -= temp;
    else if (s == "*")
      stk.top() *= temp;
    else if (s == "/")
      stk.top() /= temp;
    else
      stk.top() = pow(stk.top(), temp);
  }
  return stk.top();
}
int main() {
  string input = "2 1 + 3 *";
  cout << postfix(input);
}
