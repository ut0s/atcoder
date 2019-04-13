/**
  @date Time-stamp: <2019-04-13 22:38:15 tagashira>
  @file a.cpp
  @brief https://atcoder.jp/contests/abc123/tasks/abc124_c
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
  vector<char> vS;
  for (i = 0; i < S.size(); i++) {
    vS.push_back(S[i]);
  }

  int operation = 0;
  if (S.size() == 1) {
    cout << operation << "\n";
  } else {
    for (i = 1; i < S.size(); i++) {
      if (vS[i - 1] == vS[i]) {
        operation++;
        vS[i + 1] = vS[i];
        vS[i]     = vS[i] == 1 ? 0 : 1;
        // cout << vS << "\n";
      }
    }
    cout << operation << "\n";
  }

  return 0;
}
