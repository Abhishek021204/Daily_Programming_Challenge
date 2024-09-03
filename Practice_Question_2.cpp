#include <iostream>
#include <queue>
#include <vector>

using namespace std;

double median(vector<int> &arr) {
  int n = arr.size(), mid = n / 2 + 1;
  priority_queue<int> maxHeap(arr.begin(), arr.begin() + mid);
  for (int i = mid; i < n; i++) {
    maxHeap.push(arr[i]);
    maxHeap.pop();
  }
  if (n % 2)
    return maxHeap.top();
  double temp = maxHeap.top();
  maxHeap.pop();
  return (temp + maxHeap.top()) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/abhi/cpp_code/in.txt", "r", stdin);
  freopen("/home/abhi/cpp_code/out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
  ios::sync_with_stdio(false);
  /*input format
   * 5
   * 3 2 1 4 5
   */
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << median(arr);
}
