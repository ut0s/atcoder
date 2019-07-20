/**
  @file b.cpp
  @title B - Golden Apple
  @url https://atcoder.jp/contests/abc134/tasks/abc134_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N, D;
  cin >> N >> D;

  cout << ceil((double)N / (double)(2 * D + 1)) << endl;
  return 0;
}
