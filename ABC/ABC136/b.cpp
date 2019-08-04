/**
  @file b.cpp
  @title B - Uneven Numbers
  @url https://atcoder.jp/contests/abc136/tasks/abc136_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int i;

  int N;
  cin >> N;

  int ans = 0;
  for (i = 1; i <= N; i++) {
    if ((to_string(i).size()) % 2 != 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
