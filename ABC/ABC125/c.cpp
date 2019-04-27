/**
  @date Time-stamp: <2019-04-28 00:30:16 tagashira>
  @file c.cpp
  @brief https://atcoder.jp/contests/abc125/tasks/abc125_c
**/

#include <algorithm>
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
  uint i, j;

  for (i = 0; i < N; i++) {
    cin >> tmpA;
    A.push_back(tmpA);
  }

  // gcd test
  // cout << gcd(1071, 1029) << "\n"; //21
  // mluti gcd test
  // cout << multi_gcd({4, 6, 8}) << "\n"; //2

  uint tmp_gcd  = 0;
  uint omit_idx = 0;
  if (N == 2) {
    cout << *max_element(A.begin(), A.end()) << "\n";
  } else {
    for (j = 0; j < N; j++) {
      vector<uint> omitA;

      for (i = 0; i < N; i++) {
        if (i != omit_idx) {
          omitA.push_back(A[i]);
        }
      }

      tmp_gcd = max({tmp_gcd, multi_gcd(omitA)});

      // cout << "omit_idx:" << omit_idx << "\n";
      // cout << "tmp_gcd:" << tmp_gcd << "\n";

      omit_idx++;
    }
    cout << tmp_gcd << "\n";
  }

  return 0;
}
