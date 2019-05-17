/**
  @date Time-stamp: <2019-05-17 05:01:31 tagashira>
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
  unsigned int i, j;

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

  string query = "AC";
  for (i = 0; i < Q; i++) {
    string sub = S.substr(l[i] - 1, r[i] - l[i] + 1);
    // cout << sub << "\n"; // for debug
    unsigned int counter = 0;

    for (j = 0; j < sub.length() - 1; j++) {
      // cout << sub.substr(j, 2) << "\n"; // for debug
      if (sub.substr(j, 2) == query) counter++;
    }
    cout << counter << endl;
  }

  return 0;
}
