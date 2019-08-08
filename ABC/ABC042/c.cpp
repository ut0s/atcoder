/**
  @file c.cpp
  @title C - こだわり者いろはちゃん / Iroha's Obsession
  @url https://atcoder.jp/contests/abc042/tasks/arc058_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int ret = 1e6;

int dfs(int now, const int N, const set<int> like) {
  // end condition
  if (N <= now && now < 1e5) {
    return now;
  }

  for (auto l : like) {
    int next = now * 10 + l;
    // cout << now << " -> " << next << "\n";

    if (next == 0) continue;

    if (N <= next && next < 1e5) {
      ret = min(ret, dfs(next, N, like));
    } else {
      ret = dfs(next, N, like);
    }
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;

  set<int> like = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> D(K);
  REP(i, K) {
    cin >> D[i];
    like.erase(D[i]);
  }

  // for (auto e : like) {
  //   cout << e << endl;
  // }

  cout << dfs(0, N, like) << endl;
  return 0;
}
