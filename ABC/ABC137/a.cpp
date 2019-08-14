/**
  @file a.cpp
  @title A - +-x
  @url https://atcoder.jp/contests/abc137/tasks/abc137_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int A, B;
  cin >> A >> B;

  cout << max({A + B, A - B, A * B}) << endl;
  return 0;
}
