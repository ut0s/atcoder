/**
  @date Time-stamp: <2019-06-25 19:56:11 tagashira>
  @file b.cpp
  @title B - K-th Common Divisor
  @brief https://atcoder.jp/contests/abc120/tasks/abc120_b
**/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  if (K == 1) {
    cout << gcd(A, B) << endl;
  } else {
    vector<int> div;
    div.push_back(gcd(A, B));

    for (int i = div[0]-1; i > 0; i--) {
      if ((A % i == 0) && (B % i == 0)) {
        div.push_back(i);
      }
    }

    // show(div);
    cout << div[K - 1] << endl;
  }

  return 0;
}
