/**
  @file a.cpp
  @title A - Transfer
  @url https://atcoder.jp/contests/abc136/tasks/abc136_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  cout << max(C - (A - B), 0) << endl;
  return 0;
}
