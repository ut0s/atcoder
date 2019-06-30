/**
  @file c.cpp
  @title C - Divide the Problems
  @url https://atcoder.jp/contests/abc132/tasks/abc132_c
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

  vector<LL> d(N + 1, 0);
  for (i = 1; i <= N; i++) {
    cin >> d[i];
  }
  sort(ALL(d));

  if (d[N / 2] == d[(N / 2) + 1]) {
    cout << "0" << endl;
  } else {
    cout << d[(N / 2) + 1] - d[N / 2] << endl;
  }

  return 0;
}
