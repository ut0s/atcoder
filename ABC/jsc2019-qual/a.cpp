/**
  @file a.cpp
  @title A - Takahashi Calendar
  @url https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int M, D;
  cin >> M >> D;

  int ans = 0;
  int i, d1, d10, m;
  for (m = 2; m <= M; m++) {
    for (i = 20; i <= D; i++) {
      d1  = i % 10;
      d10 = i / 10;
      if (d1 >= 2 && d10 >= 2 && d1 * d10 == m) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
