/**
  @file d.cpp
  @title D - Powerful Discount Tickets
  @url https://atcoder.jp/contests/abc141/tasks/abc141_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N, M;
  cin >> N >> M;
  priority_queue<LL> q;

  LL tmpA;
  REP(i, N) {
    cin >> tmpA;
    q.push(tmpA);
  }

  for (int i = 0; i < M; i++) {
    LL topQ = q.top();
    q.pop();
    q.push(topQ / 2);
  }

  LL ans   = 0;
  auto tmp = q;
  while (!tmp.empty()) {
    ans += tmp.top();
    tmp.pop();
  }

  cout << ans << endl;
  return 0;
}
