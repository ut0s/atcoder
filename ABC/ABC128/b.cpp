/**
  @date Time-stamp: <2019-05-26 21:27:28 tagashira>
  @file b.cpp
  @title B - Guidebook
  @url https://atcoder.jp/contests/abc128/tasks/abc128_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream> // std::ostringstream
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, string, int> T;
bool tupleCompare(const T& first, const T& second) {
  if (std::get<1>(first) != std::get<1>(second)) return std::get<1>(first) < std::get<1>(second);
  return std::get<2>(first) > std::get<2>(second);
}

int main(int argc, char* argv[]) {
  uint N;
  cin >> N;

  vector<tuple<int, string, int>> data;

  string tmpS;
  int P;
  for (uint i = 0; i < N; i++) {
    cin >> tmpS >> P;
    data.push_back(make_tuple(i+1, tmpS, P));
  }

  sort(data.begin(), data.end(), tupleCompare);

  string prev = "";
  for (uint i = 0; i < N; i++) {
    cout << get<0>(data[i]) << endl;
  }

  return 0;
}
