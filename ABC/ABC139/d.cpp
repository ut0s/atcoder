/**
  @file d.cpp
  @title D - ModSum
  @url https://atcoder.jp/contests/abc139/tasks/abc139_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  LL N;
  cin >> N;

  cout << (N - 1) * N / 2 << endl;
  return 0;
}
