/**
  @file b.cpp
  @title B - Power Socket
  @url https://atcoder.jp/contests/abc139/tasks/abc139_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  while ((A - 1) * ans + 1 < B) {
    ans++;
  }

  cout << ans << endl;
  return 0;
}
