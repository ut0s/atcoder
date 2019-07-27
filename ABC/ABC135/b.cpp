/**
  @file b.cpp
  @title B - 0 or 1 Swap
  @url https://atcoder.jp/contests/abc135/tasks/abc135_b
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
  vector<int> p_sorted(N, 0);
  REP(i, N) {
    cin >> p[i];
    p_sorted[i] = p[i];
  }
  sort(ALL(p_sorted));

  int count = 0;
  REP(i, N) {
    if (p_sorted[i] != p[i]) {
      count++;
    }
  }

  if (count == 2 || count == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
