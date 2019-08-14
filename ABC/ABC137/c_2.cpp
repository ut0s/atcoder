/**
  @file c.cpp
  @title C - Green Bin
  @url https://atcoder.jp/contests/abc137/tasks/abc137_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;
  vector<string> s(N, "");
  REP(i, N) {
    cin >> s[i];
    sort(ALL(s[i]));
  }

  sort(ALL(s));

  map<string, LL> m;
  for (int i = 0; i < N; i++) {
    m[s[i]]++;
  }

  LL ans = 0;
  for (auto e : m) {
    ans += e.second * (e.second - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}
