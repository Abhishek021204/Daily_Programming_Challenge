#include <iostream>
#include <vector>

using namespace std;

long long missingNumber(vector<int> &arr) {
  long long sum = 0, n = arr.size() + 1;
  for (int i : arr)
    sum += i;
  return (n * (n + 1)) / 2 - sum;
}
int main() {
  vector<int> input{1, 2, 4, 5};
  cout << missingNumber(input);
}
