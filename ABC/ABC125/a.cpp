/**
  @date Time-stamp: <2019-04-28 00:29:46 tagashira>
  @file a.cpp
  @url https://atcoder.jp/contests/abc125/tasks/abc125_a
**/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, T;
  cin >> A >> B >> T;

  int count = T / A;
  // cout << count << "\n";
  int sum = B * count;

  cout << sum << "\n";

  return 0;
}
