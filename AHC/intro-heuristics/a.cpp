/**
  @file a.cpp
  @title
  @url https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_a
**/

#include <bits/stdc++.h>

#include <iostream>
#include <vector>
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
#define DEBUG(x) cerr << #x << " : " << x << "\n"
#define DEBUG2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second

const int MOD = 1e9 + 7;

const float TIME_LIMIT = 1.85;
const int T0           = 4000;
const int T1           = 60;

void iostream_init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  // cout.fill('0');
  // cout.width(3);
}

int calc_score(int D, vector<int> C, vector<vector<int>> S, vector<int> T);
vector<int> get_greedy(int D, vector<int> C, vector<vector<int>> S);
vector<int> evaluate(int D, vector<int> C, vector<vector<int>> S);

int calc_score(int D, vector<int> C, vector<vector<int>> S, vector<int> T) {
  int score = 0;
  vector<int> last_di(C.size(), 0);
  for (size_t day = 0; day < T.size(); day++) {
    int contest      = T[day] - 1;
    last_di[contest] = day + 1;
    score += S[day][contest];
    for (int type_i = 0; type_i < 26; type_i++) {
      score -= C[type_i] * (day + 1 - last_di[type_i]);
    }
  }
  return score;
}

vector<int> get_greedy(int D, vector<int> C, vector<vector<int>> S) {
  vector<int> ans;
  int max_score = calc_score(D, C, S, ans);

  // cout << "initial_score: " << max_score << endl;
  for (int day = 0; day < D; day++) {
    int max_contest = 0;
    for (int contest = 0; contest < 26; contest++) {
      ans.push_back(contest + 1);
      int tmp_score = calc_score(D, C, S, ans);
      if (contest == 0) {
        max_score = tmp_score;
      }
      if (tmp_score > max_score) {
        max_score   = tmp_score;
        max_contest = contest;
      }
      ans.pop_back();
    }
    ans.push_back(max_contest + 1);
  }
  return ans;
}

vector<int> evaluate(int D, vector<int> C, vector<vector<int>> S) {
  auto time_start = std::chrono::high_resolution_clock::now();
  auto ans        = get_greedy(D, C, S);
  auto time_end   = std::chrono::high_resolution_clock::now();
  DEBUG(std::chrono::duration<double>(time_end - time_start).count());

  time_start        = std::chrono::high_resolution_clock::now();
  time_end          = time_start;
  double prev_score = calc_score(D, C, S, ans);
  DEBUG(prev_score);
  int loop = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  double T = T0;
  while (std::chrono::duration<double>(time_end - time_start).count() < TIME_LIMIT) {
    if (loop % 100 == 0) {
      double t = (std::chrono::duration<double>(time_end - time_start).count()) / TIME_LIMIT;
      T        = std::pow(T0, 1 - t) * std::pow(T1, t);
    }
    double tmp_p    = dis(gen);
    vector<int> tmp = ans;
    // 1 day switch
    if (tmp_p > 0.3) {
      int tmp_day      = std::uniform_int_distribution<>(0, D - 1)(gen);
      int tmp_type     = std::uniform_int_distribution<>(1, 26)(gen);
      tmp[tmp_day]     = tmp_type;
      double tmp_score = calc_score(D, C, S, tmp);
      if (tmp_score > prev_score) {
        // std::cout << "1day switch: score: " << tmp_score << " > prev_score: " << prev_score << std::endl;
        prev_score = tmp_score;
        ans        = tmp;
      }
    }
    // 2 day swap
    else if (tmp_p > 0.1) {
      int day_a = std::uniform_int_distribution<>(0, D - 2)(gen);
      int w     = std::uniform_int_distribution<>(1, 13)(gen);
      int day_b = std::uniform_int_distribution<>(day_a + 1, std::min(D - 1, day_a + w))(gen);
      std::swap(tmp[day_a], tmp[day_b]);
      double tmp_score = calc_score(D, C, S, tmp);
      if (tmp_score > prev_score) {
        // std::cout << "2day swap: score: " << tmp_score << " > prev_score: " << prev_score << std::endl;
        prev_score = tmp_score;
        ans        = tmp;
      }
    }
    // Simulated Annealing
    else {
      int day_a = std::uniform_int_distribution<>(0, D - 2)(gen);
      int w     = std::uniform_int_distribution<>(6, 16)(gen);
      int day_b = std::uniform_int_distribution<>(day_a + 1, std::min(D - 1, day_a + w))(gen);
      std::swap(tmp[day_a], tmp[day_b]);
      double tmp_score = calc_score(D, C, S, tmp);
      double p         = std::exp((tmp_score - prev_score) / T);
      double r         = dis(gen);
      if (tmp_score > prev_score && r < p) {
        // std::cout << "Simulated Annealing\tscore: " << tmp_score << " > prev_score: " << prev_score << std::endl;
        prev_score = tmp_score;
        ans        = tmp;
      }
    }
    loop++;
    time_end = std::chrono::high_resolution_clock::now();
  }
  // std::cout << "loop: " << loop << std::endl;
  // std::cout << "last score: " << std::fixed << prev_score << std::endl;
  return ans;
}

int main() {
  ::iostream_init();

  int D;
  cin >> D;
  vector<int> C(26);
  REP(i, 26) {
    cin >> C[i];
  }

  vector<vector<int>> S = vector<vector<int>>(D, vector<int>(26, 0));
  REP(i, D) {
    REP(j, 26) {
      cin >> S[i][j];
    }
  }

  auto ans = evaluate(D, C, S);
  for (auto a : ans) {
    cout << a << endl;
  }

  return 0;
}
