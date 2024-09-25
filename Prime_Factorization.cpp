#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> PrimeFactorization(int N) {
  int root = sqrt(N);
  vector<int> result;
  for (int i = 2; i <= root && N > 1; i++)
    while (N % i == 0) {
      result.push_back(i);
      N /= i;
    }
  if (N != 1)
    result.push_back(N);
  return result;
}
int main() {
  int N = 18;
  for (int i : PrimeFactorization(N))
    cout << i << " ";
}
