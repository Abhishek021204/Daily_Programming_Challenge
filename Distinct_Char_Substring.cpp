#include <iostream>

using namespace std;

int atmostK(string &s, int k) {
  int left = 0, right = 0, n = s.length();
  int count[26] = {}, unique = 0, result = 0;
  while (right < n) {
    unique += (!count[s[right] - 'a']);
    count[s[right] - 'a']++;
    while (unique > k) {
      count[s[left] - 'a']--;
      unique -= (!count[s[left] - 'a']);
      left++;
    }
    result += right - left + 1;
    right++;
  }
  return result;
}
int kDistinctChar(string &s, int k) {
  return atmostK(s, k) - atmostK(s, k - 1);
}
int main() {
  string s = "pqpqs";
  int k = 2;
  cout << kDistinctChar(s, k);
}
