#include <iostream>

using namespace std;

void revWord(int start, int end, string &s) {
  while (start < end)
    swap(s[start++], s[end--]);
}
string reverseWordByWord(string &s) {
  int n = s.length();
  revWord(0, n - 1, s);
  int left = 0, right = 0;

  while (right < n && s[right] == ' ')
    right++;

  while (right < n) {
    while (right < n && s[right] != ' ')
      s[left++] = s[right++];
    while (right < n && s[right] == ' ')
      right++;
    if (right < n)
      s[left++] = ' ';
  }

  s.erase(s.begin() + left, s.end());

  left = 0, right = 0, n = s.length();
  while (right < n) {
    while (right < n && s[right] != ' ')
      right++;
    revWord(left, right - 1, s);
    left = right = right + 1;
  }

  return s;
}
int main() {
  string s = "the sky is blue";
  cout << reverseWordByWord(s);
}
