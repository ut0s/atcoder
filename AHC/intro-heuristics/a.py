#!/usr/bin/env python3
# @url https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_c

import random
import time
import logging
import math
from sys import stdin
logging.basicConfig(level=logging.INFO,
                    format="%(funcName)s:\t%(message)s")

TIME_LIMIT = 1.85
T0 = 4000
T1 = 60


def get_input():
  # input = stdin.readline
  D = int(input())
  C = list(map(int, input().split()))
  S = [list(map(int, input().split())) for _ in range(D)]

  # debug print
  logging.debug('C = {}'.format(C))
  logging.debug('S = [')
  for s in S:
    logging.debug('{}'.format(s))
  logging.debug(']')
  return (D, C, S)


def calc_score(D, C, S, T):
  score = 0
  last_di = [0 for _ in range(len(C))]
  for day in range(len(T)):
    contest = T[day]-1
    last_di[contest] = day+1
    score += S[day][contest]
    for type_i in range(26):
      score -= C[type_i] * (day+1 - last_di[type_i])
  return (score, last_di)


def calc_score_fast(D, C, S, T):
  score = 0
  last_di = [0 for _ in range(len(C))]
  for day in range(len(T)):
    contest = T[day]-1
    score += S[day][contest]
    d = last_di[contest]
    score -= C[contest] * int(d*(d-1)*0.5)
    last_di[contest] = day
    # for type_i in range(26):
    #   score -= C[type_i] * (day+1 - last_di[type_i])
  for i in range(26):
    d = len(T) - last_di[i]
    score -= C[i] * int(d*(d-1)*0.5)
  return (score, last_di)


def get_greedy(D, S, C):
  ans = []
  max_score, last_di = calc_score(D, C, S, ans)
  logging.info('initial_score: {}'.format(max_score))
  for day in range(D):
    max_contest = 0
    for contest in range(26):
      ans.append(contest+1)
      tmp_score, last_di = calc_score(D, C, S, ans)
      if contest == 0:
        max_score = tmp_score
      if tmp_score > max_score:
        # save current state
        max_score = tmp_score
        max_contest = contest
      ans.pop()
    ans.append(max_contest+1)
  logging.info('greedy: {}'.format(ans))
  return ans


def evaluate(D, C, S):
  time_start = time.perf_counter()
  ans = get_greedy(D, S, C)
  time_end = time.perf_counter()
  logging.info('get_greedy time: {}'.format(time_end - time_start))

  time_start = time.perf_counter()
  time_end = time_start
  prev_score, last_di = calc_score(D, C, S, ans)
  logging.info('initial score: {}'.format(prev_score))
  loop = 0
  while time_end - time_start < TIME_LIMIT:
    if loop % 100 == 0:
      t = (time_end - time_start) / TIME_LIMIT
      T = pow(T0, 1 - t) * pow(T1, t)
    tmp_p = random.random()  # 0.0 ~ 1.0
    tmp = ans.copy()
    # 1日選んで、行動をランダムに変化
    if tmp_p > 0.3:
      tmp_day = random.randint(0, D-1)
      tmp_type = random.randint(1, 26)
      tmp[tmp_day] = tmp_type
      tmp_score, last_di = calc_score(D, C, S, tmp)
      if tmp_score > prev_score:
        logging.debug(
            '1day switch: score: {} > prev_score: {}'.format(tmp_score, prev_score))
        # save current state
        prev_score = tmp_score
        ans = tmp.copy()
    elif tmp_p > 0.1:
      day_a = random.randint(0, D-1-1)
      w = random.randint(1, 13)
      day_b = random.randint(day_a+1, min(D-1, day_a+w))
      tmp[day_a] = ans[day_b]
      tmp[day_b] = ans[day_a]
      tmp_score, last_di = calc_score(D, C, S, tmp)
      if tmp_score > prev_score:
        logging.debug(
            '2day swap: score: {} > prev_score: {}'.format(tmp_score, prev_score))
        # save current state
        prev_score = tmp_score
        ans = tmp.copy()
    else:
      day_a = random.randint(0, D-1-1)
      w = random.randint(6, 16)
      day_b = random.randint(day_a+1, min(D-1, day_a+w))
      tmp[day_a] = ans[day_b]
      tmp[day_b] = ans[day_a]
      tmp_score, last_di = calc_score(D, C, S, tmp)
      p = math.exp((tmp_score - prev_score)/T)
      r = random.random()
      if tmp_score > prev_score and r < p:
        logging.debug(
            'Simulated Annealing\tscore: {} > prev_score: {}'.format(tmp_score, prev_score))
        # save current state
        prev_score = tmp_score
        ans = tmp.copy()
    loop += 1
    time_end = time.perf_counter()
  logging.info('loop: {}'.format(loop))
  logging.info('last score: {}'.format(format(prev_score, ',')))
  return ans


def main():
  D, C, S = get_input()
  ans = evaluate(D, C, S)
  # logging.info(f'last ans: {ans}')
  for a in ans:
    print(a)


if __name__ == "__main__":
  time_start = time.perf_counter()
  main()
  time_end = time.perf_counter()
  logging.info('total time: {}'.format(time_end - time_start))
