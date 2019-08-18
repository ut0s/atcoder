/**
  @file a.cpp
  @title A - Red or Not
  @url https://atcoder.jp/contests/abc138/tasks/abc138_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int a;
  string s;
  cin >> a;
  cin >> s;

  if (a >= 3200) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }

  return 0;
}
