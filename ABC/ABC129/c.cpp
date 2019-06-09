/**
  @date Time-stamp: <2019-06-09 22:41:03 tagashira>
  @file c.cpp
  @title C - Typical Stairs
  @brief https://atcoder.jp/contests/abc129/tasks/abc129_c
**/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream> // std::ostringstream
#include <string>
#include <vector>

using namespace std;

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

long long facctorial(int k) {
  long long sum = 1;
  for (int i = 1; i <= k; ++i) {
    sum *= i;
  }
  return sum;
}

long long calc_path(int sep) {
  int i;
  long long tmpS = 0;
  if (sep % 2 == 0) {
    for (i = 0; i <= sep / 2; i++) {
      int two = i;
      int one = sep - 2 * i;
      tmpS    += facctorial(one + two) / (facctorial(one) * facctorial(two));
    }
  } else {
    for (i = 0; i <= (sep - 1 )/ 2; i++) {
      int one = sep - 2 * i;
      int two = i;
      // cout << "Here" << endl;
      // cout << "1:" << one << endl;
      // cout << "2:" << two << endl;
      tmpS += facctorial(one + two) / (facctorial(one) * facctorial(two));
    }
  }

  return tmpS;
}

int main(int argc, char* argv[]) {
  uint N, M;
  cin >> N >> M;

  vector<uint> a(M, 0);
  for (uint i = 0; i < M; i++) {
    cin >> a[i];
  }
  // show(a);

  for (uint i = 1; i < M; i++) {
    if (a[i] - a[i - 1] == 1) {
      cout << "0" << endl;
      exit(0);
    }
  }

  vector<int> separate(M + 1, 0);
  separate[M] = N - *(a.end() - 1) - 1;
  for (uint i = 0; i < M; i++) {
    if (i == 0) {
      separate[i] = a[i] - 0 - 1;
    } else {
      separate[i] = a[i] - a[i - 1] - 2;
    }
  }
  // show(separate);

  long long sum = 0;
  for (uint i = 0; i < M + 1; i++) {
    sum += calc_path(separate[i]);
  }
  cout << sum%1000000007 << endl;

  return 0;
}
