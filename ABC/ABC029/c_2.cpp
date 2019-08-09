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

void f(int rest, string s) {
  if (rest == 0) {
    cout << s << endl;
  } else {
    for (char c = 'a'; c <= 'c'; c++) {
      f(rest - 1, s + c);
    }
  }
}

int main() {
  int N;
  cin >> N;

  f(N, "");

  return 0;
}
