#include <iostream>
#include <vector>

using namespace std;

void DutchNationalFlag(vector<int> &input) {
  int n = input.size();
  int zero_idx = 0, two_idx = n - 1;
  for (int i = 0; i <= two_idx; i++) {
    if (input[i] == 0) {
      swap(input[i], input[zero_idx]);
      zero_idx++;
    } else if (input[i] == 2) {
      swap(input[i], input[two_idx]);
      two_idx--;
      i--;
    }
  }
}

int main() {
  vector<int> input{0, 1, 2, 1, 0, 2, 1, 0};
  DutchNationalFlag(input);
  for (int i : input)
    cout << i << " ";
}
