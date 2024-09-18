#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string countSort(string &s) {
  int count[26] = {};
  for (char c : s)
    count[c - 'a']++;
  string result;
  for (int i = 0; i < 26; i++)
    result += string(count[i], i + 'a');
  return result;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<int>> group;
  int n = strs.size();
  for (int i = 0; i < n; i++)
    group[countSort(strs[i])].push_back(i);
  vector<vector<string>> result;
  for (auto &[s, v] : group) {
    result.push_back({});
    for (auto i : v)
      result.back().push_back(strs[i]);
  }
  return result;
}
int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  for (auto &v : groupAnagrams(strs)) {
    for (auto &s : v)
      cout << s << " ";
    cout << endl;
  }
}
