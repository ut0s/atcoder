/**
  @date Time-stamp: <2019-06-09 21:10:55 tagashira>
  @file b.cpp
  @title B - Balance
  @brief https://atcoder.jp/contests/abc129/tasks/abc129_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<int> W(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }

  int S1, S2;
  int ans = 1000;
  for (int T = 0; T < N; T++) {
    S1 = std::accumulate(W.begin(), W.begin() + T, 0);
    S2 = std::accumulate(W.begin() + T, W.end(), 0);

    ans = abs(S1 - S2) < ans ? abs(S1 - S2) : ans;
  }

  cout << ans << endl;

  return 0;
}
