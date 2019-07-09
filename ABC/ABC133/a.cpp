/**
  @file a.cpp
  @title 404 Not Found - AtCoder
  @url https://atcoder.jp/contests/abc133/tasks/abc133_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int ans = (N * A) > B ? B : N * A;

  cout << ans << endl;

  return 0;
}
