/**
  @date Time-stamp: <2019-05-25 21:14:54 tagashira>
  @file b.cpp
  @title B - Algae
  @brief https://atcoder.jp/contests/abc127/tasks/abc127_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream> // std::ostringstream
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  uint r, D, x2000;
  cin >> r >> D >> x2000;

  vector<int> x(11, r * x2000 - D);

  for (int i = 0; i < 10; i++) {
    cout << x[i] << endl;
    x[i + 1] = r * x[i] - D;
  }

  return 0;
}
