#include <iostream>
#include <vector>

using namespace std;

int tortoiseHare(vector<int> &arr) {
  int tortoise = 0, hare = 0;
  do {
    tortoise = arr[tortoise];
    hare = arr[arr[hare]];
  } while (tortoise != hare);
  tortoise = 0;
  while (tortoise != hare) {
    tortoise = arr[tortoise];
    hare = arr[hare];
  }
  return tortoise;
}
int main() {
  vector<int> input{3, 1, 3, 4, 2};
  cout << tortoiseHare(input);
}
