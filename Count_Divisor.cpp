#include <cmath>
#include <iostream>

using namespace std;

int countDivisor(int N) {
  int result = 0, root = sqrt(N);
  for (int i = 1; i <= root; i++)
    if (N % i == 0)
      result += 2;
  return result - (root * root == N);
}
int main() {
  int N = 12;
  cout << countDivisor(N);
}
