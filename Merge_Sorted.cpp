#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
      swap(arr[j - 1], arr[j]);
}
void mergeSorted(vector<int> &arr1, vector<int> &arr2) {
  int m = arr1.size(), n = arr2.size();
  int i = m - 1, j = 0;
  while (i >= 0 && j < n && arr1[i] > arr2[j]) {
    swap(arr1[i], arr2[j]);
    i--;
    j++;
  }
  // sort(arr1.begin(), arr1.end());
  // sort(arr2.begin(), arr2.end());
  insertionSort(arr1);
  insertionSort(arr2);
}
int main() {
  vector<int> arr1{1, 3, 5, 7};
  vector<int> arr2{2, 4, 6, 8};
  mergeSorted(arr1, arr2);
  for (int i : arr1)
    cout << i << " ";
  for (int i : arr2)
    cout << i << " ";
}
