/**
  @date Time-stamp: <2019-06-26 19:40:29 tagashira>
  @file b.cpp
  @title B - Digital Gifts
  @brief https://atcoder.jp/contests/abc119/tasks/abc119_b
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
  int N;
  cin >> N;

  vector<string> u(N);
  vector<long double> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> u[i];
  }

  long double ans = 0.0;
  for (int i = 0; i < N; i++) {
    if (u[i] == "JPY") {
      ans += x[i];
    } else {
      ans += x[i] * 380000;
    }
  }

  cout << ans << endl;

  return 0;
}
