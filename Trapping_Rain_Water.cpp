#include <iostream>
#include <vector>

using namespace std;

int waterTrap(vector<int> &heights) {
  int left = 0, right = heights.size() - 1;
  int maxLeft = 0, maxRight = 0;
  int result = 0;
  while (left < right) {
    maxLeft = max(maxLeft, heights[left]);
    maxRight = max(maxRight, heights[right]);
    if (maxLeft <= maxRight) {
      result += maxLeft - heights[left];
      left++;
    } else {
      result += maxRight - heights[right];
      right--;
    }
  }
  return result;
}
int main() {
  vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << waterTrap(arr);
}
