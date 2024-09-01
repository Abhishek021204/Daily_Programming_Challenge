#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int KthLargest(vector<int> &arr, int k) {
  int n = arr.size();
  priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(),
                                                         arr.begin() + k);
  for (int i = k; i < n; i++) {
    minHeap.push(arr[i]);
    minHeap.pop();
  }
  return minHeap.top();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/abhi/cpp_code/in.txt", "r", stdin);
  freopen("/home/abhi/cpp_code/out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
  ios::sync_with_stdio(false);

  /* input
   * 6
   * 3 2 1 5 6 4
   * 2
   */
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> k;
  if (n < k)
    cout << "Not Possible";
  else
    cout << KthLargest(arr, k);
}
