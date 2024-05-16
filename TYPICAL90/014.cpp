/**
  @file 014.cpp
  @title 014 - We Used to Sing a Song Together (★3)
  @url https://atcoder.jp/contests/typical90/tasks/typical90_n
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
#define RREP(i, N) for (int i = ((int)(N)-1); i >= 0; i--)
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

  int N;
  cin >> N;
  vector<LL> A(N);
  vector<LL> B(N);
  REP(i, N) {
    cin >> A[i];
  }
  REP(i, N) {
    cin >> B[i];
  }

  SORT(A);
  SORT(B);

  LL ans = 0;
  REP(i, N) {
    ans += abs(A[i] - B[i]);
  }
  OUT(ans);

  return 0;
}
