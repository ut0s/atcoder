/**
  @date Time-stamp: <2019-06-22 21:33:13 tagashira>
  @file b.cpp
  @title B - Bite Eating
  @brief https://atcoder.jp/contests/abc131/tasks/abc131_b
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  vector<int> taste(N, 0);
  int sum       = 0;
  int index     = 0;
  int abs_value = 100000;
  for (int i = 0; i < N; i++) {
    taste[i] = L + i;
    sum += taste[i];
    if (abs_value > abs(taste[i])) {
      abs_value = abs(taste[i]);
      index     = i;
    }
  }

  cout << sum - taste[index] << endl;

  return 0;
}
