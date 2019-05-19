/**
  @date Time-stamp: <2019-05-19 10:53:21 tagashira>
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

  //index:  0 1 2 3 4 5 6 7
  //string: A C A C T A C G
  //memo:  0 0 1 1 2 2 2 3 4 // Cumulative sum
  //index: 0 1 2 3 4 5 6 7 8

  vector<int> sum(N + 1, 0);
  for (i = 1; i < N + 1; i++) {
    sum[i + 1] = sum[i];
    if (S[i - 1] == 'A' && S[i] == 'C') sum[i + 1]++;
  }

  // for debug
  // for (i = 0; i < N + 1; i++) {
  //   cout << sum[i] << " ";
  // }
  // cout << "\n";

  for (i = 0; i < Q; i++) {
    cout << sum[r[i]] - sum[l[i]] << endl;
  }

  return 0;
}
