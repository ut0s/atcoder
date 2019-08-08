/**
  @file c.cpp
  @title C - 755
  @url https://atcoder.jp/contests/abc114/tasks/abc114_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int ret = 0;

void dfs(int now, const int N) {
  string S = to_string(now);
  if (1 <= now && now <= N
      && S.find("3") != string::npos
      && S.find("5") != string::npos
      && S.find("7") != string::npos) {
    // cout << S << endl; //debug
    ret++;
  }

  if (0 <= now && now <= N) {
    now = now * 10;
    dfs(now + 3, N);
    dfs(now + 5, N);
    dfs(now + 7, N);
  }
}

int main() {
  int N;
  cin >> N;

  dfs(0, N);
  cout << ret << endl;
  return 0;
}
