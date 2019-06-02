#!/bin/bash
# @date Time-stamp: <2019-06-02 20:52:41 tagashira>
# @file install-oj.sh
# @brief

DOTFILES="$HOME/dotfiles"

if [ $(which porg) ]; then
    echo 'porg command found'
    porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
else
    echo 'porg command not found ...'
    eval ${DOTFILES}/etc/init/00-install-porg.sh &&\
      porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
fi
