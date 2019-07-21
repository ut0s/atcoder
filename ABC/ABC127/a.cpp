/**
  @date Time-stamp: <2019-05-25 21:08:58 tagashira>
  @file a.cpp
  @title A - Ferris Wheel
  @url https://atcoder.jp/contests/abc127/tasks/abc127_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  uint A, B;
  cin >> A >> B;

  if (A >= 13) {
    cout << B << endl;
  } else if (A >= 6) {
    cout << B / 2 << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}
