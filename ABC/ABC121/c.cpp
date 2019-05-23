/**
  @date Time-stamp: <2019-05-23 13:08:30 tagashira>
  @file c.cpp
  @title C - Energy Drink Collector
  @brief https://atcoder.jp/contests/abc121/tasks/abc121_c
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
  uint i;
  long unsigned int N, M;
  cin >> N >> M;
  vector<pair<long unsigned int, long unsigned int>> AB;

  pair<long unsigned int, long unsigned int> tmpP;
  for (i = 0; i < N; i++) {
    cin >> tmpP.first >> tmpP.second;
    AB.push_back(tmpP);
  }

  sort(AB.begin(), AB.end());

  long unsigned int ans = 0;
  for (i = 0; i < N && M > 0; i++) {
    ans += AB[i].first * min(M, AB[i].second);
    M -= min(M, AB[i].second);
  }

  cout << ans << endl;

  return 0;
}
