#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> windowMaximum(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> result(n - k + 1);
  deque<pair<int, int>> monotonicQ;
  for (int i = 0; i < n; i++) {
    while (!monotonicQ.empty() && monotonicQ.back().second < arr[i])
      monotonicQ.pop_back();
    monotonicQ.push_back({i, arr[i]});
    if (i < k - 1)
      continue;
    result[i - k + 1] = monotonicQ.front().second;
    if (!monotonicQ.empty() && monotonicQ.front().first == i - k + 1)
      monotonicQ.pop_front();
  }
  return result;
}
int main() {
  vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  for (int i : windowMaximum(arr, k))
    cout << i << " ";
}
