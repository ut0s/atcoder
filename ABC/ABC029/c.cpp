/**
  @file c.cpp
  @title C - Brute-force Attack
  @url https://atcoder.jp/contests/abc029/tasks/abc029_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

vector<string> pass;

void dfs(string now, const int N) {
  if ((int)now.size() == N) {
    pass.push_back(now);
  } else {
    dfs(now + "a", N);
    dfs(now + "b", N);
    dfs(now + "c", N);
  }
}

int main() {
  int N;
  cin >> N;

  dfs("", N);
  sort(ALL(pass));

  for (auto e : pass) {
    cout << e << "\n";
  }

  return 0;
}
