/**
  @date Time-stamp: <2019-05-19 21:30:39 tagashira>
  @file b.cpp
  @title B - YYMM or MMYY
  @url https://atcoder.jp/contests/abc126/tasks/abc126_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_month(int num) {
  return (1 <= num && num <= 12);
}

bool is_year(int num) {
  return (0 <= num && num <= 99);
}

int main(int argc, char* argv[]) {
  string S;
  cin >> S;

  int mae, ato;

  mae = stoi(S.substr(0, 2));
  ato = stoi(S.substr(2, 2));

  // cout << mae << endl;
  // cout << ato << endl;

  if ((is_year(mae) && is_month(ato)) && (is_month(mae) && is_year(ato))) {
    cout << "AMBIGUOUS" << endl;
  } else if (is_year(mae) && is_month(ato)) {
    cout << "YYMM" << endl;
  } else if (is_month(mae) && is_year(ato)) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }

  return 0;
}
