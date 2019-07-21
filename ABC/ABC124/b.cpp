/**
  @date Time-stamp: <2019-04-13 22:05:44 tagashira>
  @file a.cpp
  @url https://atcoder.jp/contests/abc123/tasks/abc124_b
**/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;
  vector<int> H;
  int tmp;
  int i;
  for (i = 0; i < N; i++) {
    cin >> tmp;
    H.push_back(tmp);
  }

  // for (i = 0; i < N; i++) {
  //   cout << H[i] << "\n";
  // }

  int cansee = 0;
  for (i = 0; i < N; i++) {
    auto last = H.begin() + i + 1;
    // cout << "last " << *last << "\n";
    // cout << H[i] << ":" << *max_element(H.begin(), last) << "\n";
    if (H[i] == *max_element(H.begin(), last)) {
      cansee++;
    }
  }

  cout << cansee << "\n";

  return 0;
}
