/**
  @file c.cpp
  @title C - Alchemist
  @url https://atcoder.jp/contests/abc138/tasks/abc138_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;
  vector<double> v(N, 0);

  REP(i, N) {
    cin >> v[i];
  }
  sort(ALL(v));

  if (N == 2) {
    cout << (v[0] + v[1]) / 2 << endl;
  } else {
    for (int i = 0; i < N - 1; i++) {
      double ave = (v[0] + v[1]) / 2;
      v.erase(v.begin());
      v.erase(v.begin());
      v.insert(v.begin(), ave);
    }

    cout << v[0] << endl;
  }

  return 0;
}
