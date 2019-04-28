/**
  @date Time-stamp: <2019-04-29 08:35:45 tagashira>
  @file c.cpp
  @brief https://atcoder.jp/contests/abc125/tasks/abc125_c
**/

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

uint gcd(uint a, uint b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

uint multi_gcd(vector<uint> a) {
  if (a.size() == 2) {
    return gcd(a[0], a[1]);
  } else {
    vector<uint> tmp(a.begin() + 1, a.end());
    return gcd(a[0], multi_gcd(tmp));
  }
}

int main(int argc, char* argv[]) {
  uint N;
  cin >> N;
  vector<uint> A(0, N);
  uint tmpA;
  uint i;

  for (i = 0; i < N; i++) {
    cin >> tmpA;
    A.push_back(tmpA);
  }

  // gcd test
  // cout << gcd(1071, 1029) << "\n"; //21
  // mluti gcd test
  // chrono::system_clock::time_point start, end;
  // cout << multi_gcd({4, 6, 8}) << "\n"; //2
  // start = chrono::system_clock::now();
  // for (i = 0; i < 100; i++) {
  //   multi_gcd({4, 6, 8});
  // }
  // end         = chrono::system_clock::now();
  // double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
  // printf("gcd time %lf[ms]\n", time / 100);

  // 累積 GCD (左と右両方)
  vector<uint> left(N + 1, 0), right(N + 1, 0);
  for (i = 0; i < N; ++i) {
    left[i + 1] = gcd(A[i], left[i]);
  }
  for (i = N - 1; i > 0; --i) { //right は集計の際にi+1から始まるからidxの０は不必要
    right[i] = gcd(A[i], right[i + 1]);
  }

  // 集計
  vector<uint> M;
  for (i = 0; i < N; ++i) {
    // 左側
    uint l = left[i];

    // 右側
    uint r = right[i + 1];

    M.push_back(gcd(l, r));
  }
  cout << *max_element(M.begin(), M.end()) << endl;

  return 0;
}
