#!/usr/bin/env python3

# @date Time-stamp: <2019-04-20 21:58:06 tagashira>
# @file a.cpp
# @brief https://tenka1-2019-beginner.contest.atcoder.jp/tasks/tenka1_2019_b

N = int(input())
S = str(input())
K = int(input())

replace_char = S[K-1]
# print(replace_char)

output= ""
for char in S:
  if char != replace_char:
    output +="*"
  else:
    output +=char

print(output)
