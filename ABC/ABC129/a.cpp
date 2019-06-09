/**
  @date Time-stamp: <2019-06-09 21:02:12 tagashira>
  @file a.cpp
  @title A - Airplane
  @brief https://atcoder.jp/contests/abc129/tasks/abc129_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int P, Q, R;
  cin >> P >> Q >> R;

  cout << min(P+Q,min(P+R,Q+R))<< endl;

  return 0;
}
