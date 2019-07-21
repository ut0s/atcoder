/**
  @date Time-stamp: <2019-05-26 21:04:25 tagashira>
  @file a.cpp
  @title A - Apple Pie
  @url https://atcoder.jp/contests/abc128/tasks/abc128_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  uint A, P;
  cin >> A >> P;

  cout << (int)((A * 3 + P) * 0.5) << endl;

  return 0;
}
