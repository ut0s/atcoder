/**
  @file a.cpp
  @title A - Harmony
  @url https://atcoder.jp/contests/abc135/tasks/abc135_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int A, B;
  cin >> A >> B;

  if (min(A, B) == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    REP(k, max(A, B)) {
      if (abs(A - k) == abs(B - k)) {
        cout << k << endl;
        return 0;
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
