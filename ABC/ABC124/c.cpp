/**
  @date Time-stamp: <2019-05-14 21:32:14 tagashira>
  @file a.cpp
  @url https://atcoder.jp/contests/abc124/tasks/abc124_c
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int i;

  string S;
  cin >> S;

  // @ref https://atcoder.jp/contests/abc124/submissions/4942940
  if (S.size() == 1) {
    cout << "0"
         << "\n";
  } else {
    int pattern0 = 0;
    int pattern1 = 0;

    string a = "", b = "";
    for (int i = 0; i < S.length(); i++) {
      if (i % 2 == 0) {
        a += "0";
        b += "1";
      } else {
        a += "1";
        b += "0";
      }
    }

    for (i = 0; i < S.length(); i++) {
      if (S[i] != a[i]) pattern0++;
      if (S[i] != b[i]) pattern1++;
    }

    cout << min(pattern0, pattern1) << "\n";
  }

  return 0;
}
