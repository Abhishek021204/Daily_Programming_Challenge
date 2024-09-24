#include <iostream>

using namespace std;

long long GCD(long long a, long long b) {
  while (a && b) {
    a %= b;
    swap(a, b);
  }
  return max(a, b);
}
long long LCM(long long N, long long M) { return (N * M) / GCD(N, M); }
int main() {
  long long N = 4, M = 6;
  cout << LCM(N, M);
}
