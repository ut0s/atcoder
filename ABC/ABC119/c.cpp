/**
  @file c.cpp
  @title C - Synthetic Kadomatsu
  @url https://atcoder.jp/contests/abc119/tasks/abc119_c
**/

#include <bits/stdc++.h>
using namespace std;

int dfs(int current, int a, int b, int c, int N, int A, int B, int C, vector<int> l) {
  if (current == N) {
    if (min({a, b, c}) > 0) {
      return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    } else {
      return 1e9;
    }
  }

  int ret0 = dfs(current + 1, a, b, c, N, A, B, C, l);
  int ret1 = dfs(current + 1, a + l[current], b, c, N, A, B, C, l) + 10;
  int ret2 = dfs(current + 1, a, b + l[current], c, N, A, B, C, l) + 10;
  int ret3 = dfs(current + 1, a, b, c + l[current], N, A, B, C, l) + 10;

  return min({ret0, ret1, ret2, ret3});
}

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;

  vector<int> l(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> l[i];
  }

  cout << dfs(0, 0, 0, 0, N, A, B, C, l) << endl;

  return 0;
}
