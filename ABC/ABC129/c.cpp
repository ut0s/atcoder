/**
  @file c.cpp
  @title C - Typical Stairs
  @brief https://atcoder.jp/contests/abc129/tasks/abc129_c
**/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  int N, M;
  cin >> N >> M;

  // long long mod = 1000000007;
  const long long mod = 1e9 + 7;

  vector<bool> hole(N + 1, false);
  int a;
  for (int i = 0; i < M; i++) {
    cin >> a;
    hole[a] = true;
  }
  // show(hole);

  vector<long long> dp(N + 2, 0);
  dp[N] = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (hole[i]) {
      dp[i] = 0;
    } else {
      dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
    }
  }

  cout << dp[0] << endl;

  return 0;
}
