/**
  @date Time-stamp: <2019-06-02 20:41:48 tagashira>
  @file b.cpp
  @title B - Sumo
  @url https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_b
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

int main(int argc, char* argv[]) {
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == 'o') count++;
  }

  if (count >= 8) {
    cout << "YES" << endl;
  } else if (15 - S.length() >= 8 - count) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
