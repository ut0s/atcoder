/**
  @file d.cpp
  @title D - 1
  @url https://atcoder.jp/contests/abc029/tasks/abc029_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;

  string S = "";
  for (int i = 1; i <= N; i++) {
    S += to_string(i);
  }

  cout << count(ALL(S), '1') << endl;
  return 0;
}
