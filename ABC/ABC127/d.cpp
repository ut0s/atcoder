/**
  @date Time-stamp: <2019-05-26 13:19:58 tagashira>
  @file d.cpp
  @title D - Integer Cards
  @brief https://atcoder.jp/contests/abc127/tasks/abc127_d
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef pair<uint, long unsigned int> P;
bool pairCompare(const P& firstElof, const P& secondElof) {
  return firstElof.second > secondElof.second;
}

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

template <class T1, class T2>
void show(vector<pair<T1, T2>>& v, int x) {
  if (x == 1) {
    for (uint i = 0; i < v.size(); i++) {
      cout << v[i].first << " ";
    }
  } else if (x == 2) {
    for (uint i = 0; i < v.size(); i++) {
      cout << v[i].second << " ";
    }
  } else {
    cout << "Wrong Argument";
  }
  cout << "\n";
}

int main(int argc, char* argv[]) {
  uint N, M;
  cin >> N >> M;

  vector<long unsigned int> A(N, 0);
  for (uint i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<pair<uint, long unsigned int>> BC(M);
  for (uint i = 0; i < M; i++) {
    cin >> BC[i].first >> BC[i].second;
  }

  for (uint i = 0; i < N; i++) {
    pair<uint, long unsigned int> tmpPair = make_pair(1, A[i]);
    BC.push_back(tmpPair);
  }

  // sort(A.begin(), A.end(), greater<vector<long unsigned int>::value_type>());
  sort(BC.begin(), BC.end(), pairCompare);

  long unsigned int ans = 0;
  for (uint count = 0; N > 0; count++) {
    ans += BC[count].second * min(BC[count].first, N);
    N -= min(BC[count].first, N);
    // cout << "count:" << count << "\nans: " << ans << " N: " << N << endl;
  }

  cout << ans << endl;

  return 0;
}
