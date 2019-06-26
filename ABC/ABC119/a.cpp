/**
  @date Time-stamp: <2019-06-26 18:58:54 tagashira>
  @file a.cpp
  @title A - Still TBD
  @brief https://atcoder.jp/contests/abc119/tasks/abc119_a
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string year  = S.substr(0, 4);
  string month = S.substr(5, 2);
  string date  = S.substr(8, 2);
  // cout << year << month << day << endl;

  int day = stoi(year) + stoi(month) * 31 + stoi(date);

  if (day <= (2019 + 4 * 31 + 30)) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }

  return 0;
}
