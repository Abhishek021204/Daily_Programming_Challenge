#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int repeatKTimes(vector<int> &arr, int k) {
  unordered_map<int, int> count;
  for (int i : arr)
    count[i]++;
  for (int i : arr)
    if (count[i] == k)
      return i;
  return -1;
}
int main() {
  vector<int> arr{3, 1, 4, 4, 5, 2, 6, 1, 4};
  int k = 2;
  cout << repeatKTimes(arr, k);
}
