/**
  @date Time-stamp: <2019-05-19 12:14:02 tagashira>
  @file b.cpp
  @title B - Can you solve this?
  @url https://atcoder.jp/contests/abc121/tasks/abc121_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream> // std::ostringstream
#include <string>
#include <vector>

using namespace std;

bool can_you_solve_this(vector<int> Aj, vector<int> B, int C) {
  int sum = 0;
  for (uint i = 0; i < Aj.size(); i++) {
    sum += Aj[i] * B[i];
  }
  sum += C;
  return (sum > 0);
}

int main(int argc, char* argv[]) {
  uint i, j;
  uint N, M;
  int C;
  cin >> N >> M >> C;

  vector<int> B(M, 0);
  int tmpB;
  for (i = 0; i < M; i++) {
    cin >> tmpB;
    B.push_back(tmpB);
  }

  vector<vector<int>> A(N, vector<int>(M, 0));
  int tmpA;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      cin >> tmpA;
      A[i].push_back(tmpA);
    }
  }

  uint ans = 0;
  for (i = 0; i < N; i++) {
    if (can_you_solve_this(A[i], B, C)) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
