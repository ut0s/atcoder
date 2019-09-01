/**
  @file c.cpp
  @title C - Lower
  @url https://atcoder.jp/contests/abc139/tasks/abc139_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)


int main() {
  int N;
  cin >> N;

  vector<LL> H(N, 0);
  REP(i, N) {
    cin >> H[i];
  }

  vector<int> dp(N + 1, 0);
  int prev = H[0];
  for (int i = 1; i < N; i++) {
    if (H[i] <= prev) {
      dp[i] = dp[i - 1] + 1;
    }
    prev = H[i];
  }

  sort(ALL(dp));
  cout << dp[N] << endl;
  return 0;
}
