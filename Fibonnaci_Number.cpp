#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class BigINT {
  string num;

public:
  BigINT(long long n) {
    do {
      num += n % 10 + '0';
      n /= 10;
    } while (n);
  }
  BigINT(const BigINT &a) { num = a.num; }
  friend BigINT &operator+=(BigINT &a, const BigINT &b) {
    int i = 0, m = a.num.length(), n = b.num.length();
    bool carry = 0;
    while (i < m || i < n || carry) {
      if (i >= m)
        a.num.push_back('0');
      int sum = a.num[i] - '0' + (i < n ? b.num[i] - '0' : 0) + carry;
      a.num[i] = sum % 10 + '0';
      carry = sum / 10;
      i++;
    }
    return a;
  };
  friend void swap(BigINT &a, BigINT &b) { swap(a.num, b.num); }
  friend ostream &operator<<(ostream &os, const BigINT &a) {
    for (int i = a.num.length() - 1; i >= 0; i--)
      os << a.num[i];
    return os;
  }
};

BigINT fibonacci(int n) {
  if (n < 2)
    return BigINT(n);
  BigINT prevPrev(0), prev(1);
  for (int i = 2; i <= n; i++) {
    BigINT curr(prev);
    curr += prevPrev;
    swap(prev, prevPrev);
    swap(curr, prev);
  }
  return prev;
}

int main() {
  int n = 5;
  cout << fibonacci(n);
}
