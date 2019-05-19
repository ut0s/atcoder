/**
  @date Time-stamp: <2019-05-19 11:19:54 tagashira>
  @file a.cpp
  @title A - White Cells
  @brief https://atcoder.jp/contests/abc121/tasks/abc121_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int H, W, h, w;
  cin >> H >> W;
  cin >> h >> w;

  cout << (H-h)*(W-w) << "\n";

  return 0;
}
