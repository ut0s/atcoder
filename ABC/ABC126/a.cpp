/**
  @date Time-stamp: <2019-05-19 21:14:36 tagashira>
  @file a.cpp
  @title A - Changing a Character
  @brief https://atcoder.jp/contests/abc126/tasks/abc126_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  string S;
  cin >> S;

  cout << S << endl;

  int mae, ato;

  mae = stoi(S.substr(0, 2));
  ato = stoi(S.substr(2, 2));

  // if (1 <= mae && mae <= 12 && 1 <= ato && mae <= 12) {
  //   cout << "AMBIGUOUS" << endl;
  // } else if (0 <= mae && mae <= 99 && 1 <= ato && mae <= 12) {
  //   cout << "YYMM" << endl;
  // } else if (1 <= mae && mae <= 12 && 0 <= ato && mae <= 99) {
  //   cout << "MMYY" << endl;
  // } else {
  //   cout << "NA" << endl;
  // }

  return 0;
}
