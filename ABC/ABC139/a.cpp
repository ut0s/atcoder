/**
  @file a.cpp
  @title A - Tenki
  @url https://atcoder.jp/contests/abc139/tasks/abc139_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  string S, T;
  cin >> S >> T;

  int ans = 0;
  REP(i, 3) {
    if (S.substr(i, 1) == T.substr(i, 1)) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
