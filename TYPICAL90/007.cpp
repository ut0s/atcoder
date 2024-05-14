/**
  @file 007.cpp
  @title 007 - CP Classes
  @url https://atcoder.jp/contests/typical90/tasks/typical90_g
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())

#define REPI(i, a, b) for (LL i = LL(a); i < LL(b); ++i)
#define REP(i, N) for (LL i = LL(0); i < LL(N); ++i)
#define REPS(i, N) for (int i = 1; i <= (int)(N); i++)
#define RREP(i, N) for (int i = ((int)(N) - 1); i >= 0; i--)
#define RREPS(i, N) for (int i = ((int)(N)); i > 0; i--)

#define chmax(ret, x) ret = max(ret, x)
#define chmin(ret, x) ret = min(ret, x)

#define FILL(x, e) memset(x, e, sizeof(x))
#define ZEROS(x) fill(x, 0)

#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(RALL(x))

#define UNIQ(x) x.erase(unique(ALL(x)), x.end());

#define BIT(n) (1LL << (n))

#define OUT(x) cout << (x) << "\n"
#define DEBUG(x) cerr << #x << " : " << x << "\n"
#define DEBUG2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

const int MOD = 1e9 + 7;

void iostream_init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  // cout.fill('0');
  // cout.width(3);
}

bool check_condtion(LL candidate, const LL N, const LL L, const LL K, const vector<LL> A) {
  LL tmp_len = 0;
  LL cnt     = 0;

  REP(i, N) {
    if ((A[i] - tmp_len >= candidate) && (L - A[i] >= candidate)) {
      cnt++;
      tmp_len = A[i];
    }
  }

  return (cnt >= K);
}

int main() {
  ::iostream_init();

  LL N, Q;
  cin >> N;
  vector<LL> A(N, 0);
  REP(i, N) {
    cin >> A[i];
  }
  cin >> Q;
  vector<LL> B(Q, 0);
  REP(i, Q) {
    cin >> B[i];
  }

  SORT(A);

  vector<LL> ans(Q, MOD);
  REP(j, Q) {
    auto lower_it      = std::lower_bound(ALL(A), B[j]);
    auto prev_lower_it = lower_it != A.begin() ? lower_it - 1 : lower_it;
    DEBUG2(*prev_lower_it, *lower_it);
    ans[j] = min(abs(B[j] - *prev_lower_it), abs(B[j] - *lower_it));
    OUT(ans[j]);
  }

  /* REP(j, Q) { */
  /* } */

  return 0;
}
