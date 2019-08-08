/**
  @file a.cpp
  @title A - 和風いろはちゃんイージー / Iroha and Haiku (ABC Edition)
  @url https://atcoder.jp/contests/abc042/tasks/abc042_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int query = 100 * A + 10 * B + C;

  if (query == 755 || query == 575 || query == 557) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
