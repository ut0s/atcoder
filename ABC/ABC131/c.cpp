/**
  @file c.cpp
  @title C - Anti-Division
  @brief https://atcoder.jp/contests/abc131/tasks/abc131_c
**/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  long long min_divC  = (A - 1) / C;
  long long max_divC  = (B + 0) / C;
  long long min_divD  = (A - 1) / D;
  long long max_divD  = (B + 0) / D;
  long long min_divCD = (A - 1) / lcm(C, D);
  long long max_divCD = (B + 0) / lcm(C, D);

  long long ans = B - A + 1;
  if (min_divC == 0 && max_divC == 0) {
    // do nothing
  } else {
    ans -= (max_divC - min_divC);
  }

  if (min_divD == 0 && max_divD == 0) {
    // do nothing
  } else {
    ans -= (max_divD - min_divD);
  }

  if (min_divCD == 0 && max_divCD == 0) {
    // do nothing
  } else {
    ans += (max_divCD - min_divCD);
  }

  cout << ans << endl;

  return 0;
}
