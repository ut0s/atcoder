/**
  @date Time-stamp: <2019-05-25 23:40:38 tagashira>
  @file c.cpp
  @title C - Prison
  @url https://atcoder.jp/contests/abc127/tasks/abc127_c
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
  uint N, M;
  cin >> N >> M;
  vector<uint> L(M, 0);
  vector<uint> R(M, 0);

  for (uint i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
  }

  uint maxL = *max_element(L.begin(), L.end());
  uint minR = *min_element(R.begin(), R.end());

  int ans = minR - maxL + 1;
  if (ans >= 0) {
    cout << ans << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}
