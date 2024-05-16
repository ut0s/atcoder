/**
  @file 010.cpp
  @title 010 - Score Sum Queries（★2）
  @url https://atcoder.jp/contests/typical90/tasks/typical90_j
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef unsigned int uint;
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

int main() {
  ::iostream_init();

  int N;
  cin >> N;
  vector<int> C(N);
  int P;
  vector<int> sum1(N + 1, 0);
  vector<int> sum2(N + 1, 0);
  REP(i, N) {
    cin >> C[i] >> P;
    if (C[i] == 1) {
      sum1[i + 1] = sum1[i] + P;
      sum2[i + 1] = sum2[i];
    } else {
      sum1[i + 1] = sum1[i];
      sum2[i + 1] = sum2[i] + P;
    }
    DEBUG2(sum1[i], sum2[i]);
  }

  int Q;
  cin >> Q;
  int L;
  int R;
  REP(i, Q) {
    cin >> L >> R;
    cout << sum1[R] - sum1[L - 1] << " " << sum2[R] - sum2[L - 1] << endl;
  }

  return 0;
}
