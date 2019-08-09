/**
  @file b.cpp
  @title B - カキ
  @url https://atcoder.jp/contests/abc029/tasks/abc029_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int ret = 0;
  string S;
  while (cin >> S) {
    if (S.find("r") != string::npos) {
      ret++;
    }
  }

  cout << ret << endl;
  return 0;
}
