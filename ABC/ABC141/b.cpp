/**
  @file b.cpp
  @title B - Tap Dance
  @url https://atcoder.jp/contests/abc141/tasks/abc141_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  string S;
  cin >> S;
  int N = (int)S.size();

  bool flag = true;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0 && S[i - 1] == 'R') {
      flag = false;
    } else if (i % 2 != 0 && S[i - 1] == 'L') {
      flag = false;
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
