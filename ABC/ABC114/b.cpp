/**
  @file b.cpp
  @title B - 754
  @url https://atcoder.jp/contests/abc114/tasks/abc114_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  string S;
  cin >> S;

  int ret = 1e9 + 7;
  REP(i, S.size() - 2) {
    int tmp = stoi(S.substr(i, 3));
    ret     = min(ret, abs(753 - tmp));
  }

  cout << ret << endl;
  return 0;
}
