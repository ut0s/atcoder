/**
  @file b.cpp
  @title B - One Clue
  @url https://atcoder.jp/contests/abc137/tasks/abc137_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int K, X;
  cin >> K >> X;

  for (int i = 0; i < 2 * K - 1; i++) {
    cout << X - K + 1 + i << " ";
  }
  cout << endl;

  return 0;
}
