/**
  @file b.cpp
  @title B - Palace
  @url https://atcoder.jp/contests/abc113/tasks/abc113_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
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
#define DEBUG(x) cout << #x << " : " << x << "\n"
#define DEBUG2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

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

int main() {
  ::iostream_init();

  int N;
  cin >> N;
  int T, A;
  cin >> T >> A;

  vector<int> H(N, 0);
  vector<double> t(N, 0.0);
  vector<double> ans(N, 0.0);
  REP(i, N) {
    cin >> H[i];
    t[i]   = (double)T - (double)H[i] * 0.006;
    ans[i] = abs(t[i] - A);
  }

  OUT(1+distance(ans.begin(), min_element(ALL(ans))));
  return 0;
}
