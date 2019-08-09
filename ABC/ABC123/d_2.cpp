/**
  @file d2.cpp
  @title D - Cake 123
  @url https://atcoder.jp/contests/abc123/tasks/abc123_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<LL> A(X, 0);
  vector<LL> B(Y, 0);
  vector<LL> C(Z, 0);

  REP(i, X) { cin >> A[i]; }
  REP(i, Y) { cin >> B[i]; }
  REP(i, Z) { cin >> C[i]; }

  sort(ALL(A), std::greater<LL>());
  sort(ALL(B), std::greater<LL>());
  sort(ALL(C), std::greater<LL>());

  vector<LL> ABC;
  REP(i, X) {
    REP(j, Y) {
      REP(k, Z) {
        if (i * j * k <= K) {
          ABC.push_back(A[i] + B[j] + C[k]);
        }
      }
    }
  }
  sort(ALL(ABC), std::greater<LL>());

  REP(i, K) { cout << ABC[i] << "\n"; }

  return 0;
}
