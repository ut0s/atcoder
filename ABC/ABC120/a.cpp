/**
  @date Time-stamp: <2019-06-25 19:32:25 tagashira>
  @file a.cpp
  @title A - Favorite Sound
  @brief https://atcoder.jp/contests/abc120/tasks/abc120_a
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (B / A >= C) {
    cout << C << endl;
  } else {
    cout << B / A << endl;
  }

  return 0;
}
