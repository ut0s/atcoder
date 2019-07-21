/**
  @date Time-stamp: <2019-05-19 22:14:44 tagashira>
  @file c.cpp
  @title C - Dice and Coin
  @url https://atcoder.jp/contests/abc126/tasks/abc126_c
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  uint N, K;
  cin >> N >> K;

  long double p = 0.0;

  // cout << "K/N:  " << (double)K / (double)N << endl;
  // cout << "log2: " << log2((double)K / (double)N) << endl;
  // cout << "ceil: " << ceil(log2((double)K / (double)N)) << endl;

  uint i;
  for (i = 1; i <= N; i++) {
    if (i <= K - 1) {
      p += (long double)(1 / (long double)N) * powl(0.5l, ceil(log2((long double)K / (long double)i)));
    } else
      p += (long double)(1 / (long double)N);
  }
  cout << std::setprecision(16) << p << endl;

  return 0;
}
