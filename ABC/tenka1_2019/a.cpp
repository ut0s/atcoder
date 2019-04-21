/**
  @date Time-stamp: <2019-04-20 21:46:20 tagashira>
  @file a.cpp
  @brief https://tenka1-2019-beginner.contest.atcoder.jp/tasks/tenka1_2019_a
**/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, C;
  cin >> A >> B >> C;

  if (C - A > 0 && B - C > 0) {
    cout << "Yes"
         << "\n";
  } else if (C - B > 0 && A - C > 0) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }

  return 0;
}
