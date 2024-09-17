#include <iostream>
#include <vector>

using namespace std;

string longestPrefix(vector<string> &strs) {
  int m = strs.size(), n = strs[0].length();
  string result;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      if (j >= (int)strs[i].length() || strs[i][j] != strs[0][j])
        return result;
    }
    result += strs[0][j];
  }
  return result;
}
int main() {
  vector<string> strs{"flower", "flow", "flight"};
  cout << longestPrefix(strs);
}
