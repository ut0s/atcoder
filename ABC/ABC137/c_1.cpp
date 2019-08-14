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
  vector<map<char, int>> m(N);
  REP(i, N) {
    cin >> s[i];
    map<char, int> tmp;

    REP(k, 10) {
      tmp[s[i][k]] = 0;
    }

    REP(k, 10) {
      tmp[s[i][k]]++;
    }
    m[i] = tmp;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (m[i] == m[j]) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
