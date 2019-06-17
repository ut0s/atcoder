/**
  @file a.cpp
  @title A - Rounding
  @brief https://atcoder.jp/contests/abc130/tasks/abc130_a
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

int main(int argc, char* argv[]) {
  int X, A;
  cin >> X >> A;

  if (X < A) {
    cout << "0" << endl;
  } else {
    cout << "10" << endl;
  }

  return 0;
}
