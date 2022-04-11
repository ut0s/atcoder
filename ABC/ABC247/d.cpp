/**
  @file d.cpp
  @title
  @url https://atcoder.jp/contests/abc247/tasks/abc247_d
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

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  ::iostream_init();

  int Q;
  cin >> Q;

  // list<int> l;
  // int mode;
  // REP(i, Q) {
  //   cin >> mode;
  //   if (mode == 1) {
  //     uint x, c;
  //     cin >> x >> c;
  //     REP(i, c) {
  //       l.PB(x);
  //     }
  //   } else {
  //     uint c;
  //     cin >> c;
  //     LL sum = 0;
  //     REP(i, c) {
  //       sum += l.front();
  //       l.pop_front();
  //     }
  //     OUT(sum);
  //   }
  // }

  vector<pair<LL, LL>> l;
  int mode;

  vector<int> command;
  REP(i, Q) {
    cin >> mode;
    if (mode == 1) {
      LL x, c;
      cin >> x >> c;
      l.PB(make_pair(x, c));
    } else {
      LL c;
      cin >> c;
      command.PB(c);
    }
  }

  LL pos = 0;
  REP(i, SZ(command)) {
    LL sum = 0;
    LL c = command[i];
    while (c != 0) {
      // DEBUG(c);
      if (l[pos].SE > c) {
        sum += l[pos].FI * c;
        l[pos].SE -= c;
        c = 0;
      } else if (l[pos].SE == c) {
        sum += l[pos].FI * c;
        l[pos].SE = 0;
        c         = 0;
        pos++;
      } else {
        sum += l[pos].FI * l[pos].SE;
        c -= l[pos].SE;
        l[pos].SE = 0;
        pos++;
      }
      // DEBUG(pos);
      // DEBUG(sum);
    }
    OUT(sum);
  }

  return 0;
}
