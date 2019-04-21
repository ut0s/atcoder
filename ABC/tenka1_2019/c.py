#!/usr/bin/env python3

# @date Time-stamp: <2019-04-20 22:30:10 tagashira>
# @file a.cpp
# @brief https://tenka1-2019-beginner.contest.atcoder.jp/tasks/tenka1_2019_c

N = int(input())
S = str(input())

# print(S.replace("#.","#!"))
output =0
for i in range(1,N):
  print(S)
  if S[i] == "#":
    if i+1 < N and S[i+1] == ".":
      output +=1
      S = S.replace('.', '#', 1)

print(int(output))
