/**
  @date Time-stamp: <2019-06-22 21:12:08 tagashira>
  @file a.cpp
  @title A - Security
  @brief https://atcoder.jp/contests/abc131/tasks/abc131_a
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int count = 0;
  for (int i = 1; i < S.length(); i++) {
    if (S[i] == S[i - 1]) {
      count++;
    }
  }

  if (count != 0) {
    cout << "Bad" << endl;
  } else {
    cout << "Good" << endl;
  }

  return 0;
}
