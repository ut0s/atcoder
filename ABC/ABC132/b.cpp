/**
  @file b.cpp
  @title B - Ordinary Number
  @url https://atcoder.jp/contests/abc132/tasks/abc132_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;

  vector<int> p(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 1; i < N - 1; i++) {
    int before_pi = p[i];

    vector<int> v;
    v.push_back(p[i - 1]);
    v.push_back(p[i]);
    v.push_back(p[i + 1]);
    sort(ALL(v));
    int after_pi = v[1];

    if (before_pi == after_pi) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
