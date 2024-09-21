#include <iostream>

using namespace std;

int res_idx = -1, res_size = 0;
void expand(int left, int right, string &s) {
  int n = s.length();
  while (left >= 0 && right < n && s[left] == s[right]) {
    left--, right++;
  }
  if (right - left - 1 > res_size) {
    res_size = right - left - 1;
    res_idx = left + 1;
  }
}
string longestPalindrome(string &s) {
  int n = s.length();
  if (n == 0)
    return "";
  for (int center = 0; center < n; center++) {
    expand(center, center, s);
    expand(center, center + 1, s);
  }
  return s.substr(res_idx, res_size);
}
int main() {
  string input = "babad";
  cout << longestPalindrome(input);
}
