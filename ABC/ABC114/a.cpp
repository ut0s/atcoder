/**
  @file a.cpp
  @title A - 753
  @url https://atcoder.jp/contests/abc114/tasks/abc114_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int X;
  cin >> X;

  if (X == 3 || X == 5 || X == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
