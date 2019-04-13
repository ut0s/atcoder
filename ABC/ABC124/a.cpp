/**
  @date Time-stamp: <2019-04-13 21:18:53 tagashira>
  @file a.cpp
  @brief https://atcoder.jp/contests/abc123/tasks/abc124_a
**/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B;
  cin >> A >> B;

  if (abs(A - B) <= 1) {
    cout << A + B << endl;
  } else {
    cout << max(A, B) * 2 - 1 << "\n";
  }

  return 0;
}
