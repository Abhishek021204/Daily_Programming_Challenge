#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool validParentheses(string &s) {
  unordered_map<char, char> match{{'{', '}'}, {'(', ')'}, {'[', ']'}};
  stack<char> stk;
  for (char c : s) {
    if (match.count(c))
      stk.push(c);
    else if (!stk.empty() && c == match[stk.top()])
      stk.pop();
    else
      return false;
  }
  return true;
}
int main() {
  string input = "()";
  boolalpha(cout);
  cout << validParentheses(input);
}
