#!/bin/bash
# @file monitor_submission.sh
# @brief monitor AtCoder submission


path_to_icon="$(cd $(dirname $0) && cd ../etc && pwd)/.icon.png"

NOTIFIY_COMMAND="notify-send"
NOTIFIY_COMMAND_OPT=" -u normal --icon=${path_to_icon}"

LAP=5 #seconds
count=0

init(){
  url_icon="https://img.atcoder.jp/assets/atcoder.png"

  if [ -e $path_to_icon ]
  then
    :
  else
    curl -s $url_icon -o $path_to_icon
  fi
}

get_status(){
  local url=$1
  local status=$(curl -s $url | grep "judge-status" |cut -d "\"" -f 7 | cut -d "<" -f1 | cut -d ">" -f2)

  echo $status
}

monitor_submission(){
  local url=$1
  local status=$(get_status $url)
  ${NOTIFIY_COMMAND} ${NOTIFIY_COMMAND_OPT} $status $url > /dev/null
  echo $status
}

main(){
  init
  while true; do
    res=$(monitor_submission $@)
    if [ $res = "AC" -o $res = "RE" -o $res = "TLE" -o $res = "WA" ]
    then
      exit 0
    else
      sleep $LAP"s"
      $count=$(($count + 1))
      if [ $count -eq 18 ]
      then
        echo "one and half minutes elapsed"
      fi

    fi
  done
}

main $@
