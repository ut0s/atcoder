/**
  @date Time-stamp: <2019-05-17 22:33:02 tagashira>
  @file c.cpp
  @title C - GeT AC
  @brief https://atcoder.jp/contests/abc122/tasks/abc122_c
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
  unsigned int i;

  unsigned long int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> l, r;
  unsigned long int tmpL, tmpR;
  for (i = 0; i < Q; i++) {
    cin >> tmpL >> tmpR;
    l.push_back(tmpL);
    r.push_back(tmpR);
  }

  string query      = "AC";
  string calc_cache = "";
  for (i = 0; i < S.length() - 1; i++) {
    // cout << S.substr(i, 2) << "\n"; // for debug
    if (S.substr(i, 2) == query) {
      calc_cache += '1';
    } else {
      calc_cache += '0';
    }
  }
  // cout << calc_cache << "\n"; // for debug

  for (i = 0; i < Q; i++) {
    // cout << calc_cache.substr(l[i] - 1, r[i] - l[i]) << "\n"; // for debug
    cout << std::count(&S[l[i] - 1], &S[r[i] - l[i]], '1') << endl;
  }

  return 0;
}
