#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int> &coins, int amount) {
  vector<int> dp(amount + 1, 2e9);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++)
    for (int coin : coins)
      if (i >= coin)
        dp[i] = min(dp[i - coin] + 1, dp[i]);
  return (dp[amount] == 2e9 ? -1 : dp[amount]);
}

int main() {
  int amount = 11;
  vector<int> coins{1, 2, 5};
  cout << minCoins(coins, amount);
}
