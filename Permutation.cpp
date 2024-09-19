#include <iostream>
#include <vector>

using namespace std;

vector<string> result;
void permutation(int start, string &s) {
  int n = s.length();
  if (start == n) {
    result.push_back(s);
    return;
  }
  bool visited[26] = {};
  for (int i = start; i < n; i++) {
    if (visited[s[i] - 'a'])
      continue;
    visited[s[i] - 'a'] = true;
    swap(s[i], s[start]);
    permutation(start + 1, s);
    swap(s[i], s[start]);
  }
}
int main() {
  string input = "abc";
  permutation(0, input);
  for (auto &s : result)
    cout << s << " ";
}
