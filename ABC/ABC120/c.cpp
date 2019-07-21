/**
  @file c.cpp
  @title C - Unification
  @url https://atcoder.jp/contests/abc120/tasks/abc120_c
**/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  string S;
  cin >> S;

  int one  = 0;
  int zero = 0;

  if (S.length() == 0) {
    cout << "0" << endl;
  } else {
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '0') {
        zero++;
      } else {
        one++;
      }
    }
    cout << S.length() - abs(zero - one) << endl;
  }

  return 0;
}
