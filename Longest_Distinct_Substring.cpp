#include <iostream>

using namespace std;

int longestSubstring(string &s) {
  int left = 0, right = 0, n = s.length();
  int result = 0;
  bool present[26] = {};
  while (right < n) {
    while (present[s[right] - 'a'])
      present[s[left++] - 'a'] = false;
    present[s[right] - 'a'] = true;
    result = max(result, right - left + 1);
    right++;
  }
  return result;
}
int main() {
  string s = "abcabcbb";
  cout << longestSubstring(s);
}
