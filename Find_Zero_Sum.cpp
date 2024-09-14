#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<int, int>> zeroSum(vector<int> &arr) {
  unordered_map<int, vector<int>> prefix;
  prefix[0].push_back(-1);
  int prefixSum = 0, n = arr.size();
  vector<pair<int, int>> result;
  for (int i = 0; i < n; i++) {
    prefixSum += arr[i];
    for (int p : prefix[prefixSum])
      result.push_back({p + 1, i});
    prefix[prefixSum].push_back(i);
  }
  return result;
}
int main() {
  vector<int> arr{1, 2, -3, 3, -1, 2};
  for (auto p : zeroSum(arr))
    cout << "(" << p.first << "," << p.second << ") ";
}
