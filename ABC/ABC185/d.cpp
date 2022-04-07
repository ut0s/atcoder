/**
  @file d.cpp
  @title D - Stamp
  @url https://atcoder.jp/contests/abc185/tasks/abc185_d
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

template <class T>
void show(vector<T>& v) {
  for (LL i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  ::iostream_init();

  LL N, M;
  cin >> N >> M;

  vector<bool> num(N, false);
  vector<LL> A(M, 0);
  REP(i, M) {
    cin >> A[i];
    num[A[i] - 1] = true;
  }

  vector<LL> split;
  LL tmp = 0;
  REP(i, N) {
    if (num[i] == true) {
      if (tmp != 0) {
        split.PB(tmp);
      }
      tmp = 0;
    } else {
      tmp++;
    }
  }
  if (tmp > 0) {
    split.PB(tmp);
  }

  SORT(split);
  // show(split);

  if (N == M) {
    OUT(0);
  } else if (M == 0) {
    OUT(1);
  } else {
    double stamp_length = *min_element(ALL(split));
    // cout << "stamp L " << stamp_length << endl;

    LL ret = 0;
    for (auto e : split) {
      ret += ceil((double)e / stamp_length);
      // cout << e << " , " << ceil(e / stamp_length) << endl;
    }
    OUT(ret);
  }

  return 0;
}
