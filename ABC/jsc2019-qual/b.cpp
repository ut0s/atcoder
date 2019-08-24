/**
  @file b.cpp
  @title B - Kleene Inversion
  @url https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  LL mod = 1e9 + 7;

  LL N;
  LL K;
  cin >> N >> K;
  vector<LL> A(N, 0);
  REP(i, N) {
    cin >> A[i];
  }

  LL ans = 0;
  for (LL i = 0; i < N; i++) {
    for (LL j = i + 1; j < N; j++) {
      if (A[i] > A[j]) ans++;
    }
  }

  ans = (ans * K) % mod;

  auto reps = [](LL K) {
    if (K > 1) {
      return (K - 1) * K / 2;
    } else {
      return 0LL;
    }
  };

  for (LL i = 0; i < N; i++, ans %= mod) {
    for (LL j = 0; j < N; j++, ans %= mod) {
      if (A[i] > A[j]) {
        ans += reps(K);
      }
    }
  }

  cout << ans % mod << endl;
  return 0;
}
