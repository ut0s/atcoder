/**
  @file c.cpp
  @title C - Attack Survival
  @url https://atcoder.jp/contests/abc141/tasks/abc141_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  LL N, K, Q;
  cin >> N >> K >> Q;
  map<LL, int> m;
  LL tmpA;
  REP(i, Q) {
    cin >> tmpA;
    m[tmpA - 1]++;
  }

  REP(i, N) {
    if (K + m[i] - Q > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
