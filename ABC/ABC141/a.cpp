/**
  @file a.cpp
  @title A - Weather Prediction
  @url https://atcoder.jp/contests/abc141/tasks/abc141_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  string S;
  cin >> S;

  vector<string> v = {"Sunny", "Cloudy", "Rainy"};

  if (S == v[0]) {
    cout << v[1] << endl;
  } else if (S == v[1]) {
    cout << v[2] << endl;
  } else if (S == v[2]) {
    cout << v[0] << endl;
  }

  return 0;
}
