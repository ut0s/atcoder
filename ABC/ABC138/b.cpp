/**
  @file b.cpp
  @title B - Resistors in Parallel
  @url https://atcoder.jp/contests/abc138/tasks/abc138_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);

  double sum = 0;
  REP(i, N) {
    cin >> A[i];
    sum += (1 / (double)A[i]);
  }

  cout << fixed << 1 / sum << endl;
  return 0;
}
