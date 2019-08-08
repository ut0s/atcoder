/**
  @file b.cpp
  @title B - 文字列大好きいろはちゃんイージー / Iroha Loves Strings (ABC Edition)
  @url https://atcoder.jp/contests/abc042/tasks/abc042_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  REP(i, N) {
    cin >> S[i];
  }

  sort(ALL(S));

  string ret = "";
  REP(i, N) {
    ret += S[i];
  }

  cout << ret << endl;
  return 0;
}
