#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> leaders(vector<int> &arr) {
  int n = arr.size(), maxRight = INT_MIN;
  vector<int> result;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > maxRight)
      result.push_back(arr[i]);
    maxRight = max(maxRight, arr[i]);
  }
  reverse(result.begin(), result.end());
  return result;
}
int main() {
  vector<int> arr{16, 17, 4, 3, 5, 2};
  for (int i : leaders(arr))
    cout << i << " ";
}
