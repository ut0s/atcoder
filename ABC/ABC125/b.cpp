/**
  @date Time-stamp: <2019-04-28 00:30:00 tagashira>
  @file b.cpp
  @brief https://atcoder.jp/contests/abc125/tasks/abc125_b
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
  vector<int> C(0, N);
  vector<int> V(0, N);
  int tmpC, tmpV;
  int i;

  for (i = 0; i < N; i++) {
    cin >> tmpV;
    V.push_back(tmpV);
  }
  for (i = 0; i < N; i++) {
    cin >> tmpC;
    C.push_back(tmpC);
  }

  vector<int> sum(0, N);
  for (i = 0; i < N; i++) {
    sum.push_back(V[i] - C[i]);
  }

  sort(sum.begin(), sum.end());

  int result = 0;
  for (i = 0; i < N; i++) {
    if (sum[i] > 0) {
      result += sum[i];
    }
  }

  cout << result << "\n";

  return 0;
}
