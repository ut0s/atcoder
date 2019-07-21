/**
  @file a.cpp
  @title A - Triangle
  @url https://atcoder.jp/contests/agc036/tasks/agc036_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

vector<LL> div_list(int n) {
  vector<LL> ret;
  for (LL i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i != 1 && i * i != n) {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}

vector<LL> div_list_omit(int n) {
  vector<LL> ret;
  LL limit = n < 1e9 ? n : 1e9;
  for (LL i = 1; i * i < limit; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i != 1 && i * i != n && (n / i) < 1e9) {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  LL S;
  cin >> S;

  LL x1, x2, x3, y1, y2, y3;

  x1 = 0;
  y1 = 0;

  // vector<int> divlist = div_list(S);
  vector<LL> divlist = div_list_omit(S);
  // sort(ALL(divlist), greater<LL>());
  // show(divlist);

  REP(i, divlist.size()) {
    x2 = divlist[i];
    y2 = 0;
    x3 = 0;
    y3 = S / divlist[i];

    LL q = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    if (q == S) {
      break;
    }
  }

  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
  return 0;
}
