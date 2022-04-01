/**
  @file 004.cpp
  @title 004 - Cross Sum（★2）
  @url https://atcoder.jp/contests/typical90/tasks/typical90_d
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

  int H, W;
  cin >> H >> W;

  vector<vector<uint>> A(H, vector<uint>(W, 0));
  REP(i, H) {
    REP(j, W) {
      cin >> A[i][j];
    }
  }

  vector<uint> sumH(H, 0);
  REP(i, H) {
    REP(j, W) {
      sumH[i] += A[i][j];
    }
  }

  vector<uint> sumW(W, 0);
  REP(j, W) {
    REP(i, H) {
      sumW[j] += A[i][j];
    }
  }

  REP(i, H) {
    REP(j, W) {
      cout << sumH[i] + sumW[j] - A[i][j];
      if (j != W - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
