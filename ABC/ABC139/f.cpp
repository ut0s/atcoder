/**
  @file f.cpp
  @title
  @url https://atcoder.jp/contests/abc139/tasks/abc139_f
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

long double max_dist = -1;

void dfs(const int N, int count, LL X, LL Y, vector<bool> is_used, const vector<pair<LL, LL>> xy) {
  if (N == count) {
    max_dist = max_dist > sqrt(X * X + Y * Y) ? max_dist : sqrt(X * X + Y * Y);
  } else {
    REP(i, N) {
      if (!is_used[i]) {
        long double dis = sqrt(pow(X + xy[i].first, 2) + pow(Y + xy[i].second, 2));
        if (dis >= max_dist) {
          max_dist   = dis;
          is_used[i] = true;
          dfs(N, count + 1, X + xy[i].first, Y + xy[i].second, is_used, xy);
        }
      }
    }
  }
}

int main() {
  int N;
  cin >> N;

  vector<pair<LL, LL>> xy(N);
  REP(i, N) {
    cin >> xy[i].first >> xy[i].second;
  }

  LL X = 0, Y = 0;
  vector<bool> is_used(N, false);
  dfs(N, 0, X, Y, is_used, xy);
  cout << setprecision(20) << max_dist << endl;
  return 0;
}
