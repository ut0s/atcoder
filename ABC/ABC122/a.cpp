/**
  @date Time-stamp: <2019-05-14 21:41:58 tagashira>
  @file a.cpp
  @title A - Double Helix
  @url https://atcoder.jp/contests/abc122/tasks/abc122_a
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  char s;
  cin >> s;

  if (s == 'A') {
    cout << 'T' << "\n";
  } else   if (s == 'T') {
    cout << 'A' << "\n";
  } else   if (s == 'C') {
    cout << 'G' << "\n";
  } else   if (s == 'G') {
    cout << 'C' << "\n";
  }

  return 0;
}
