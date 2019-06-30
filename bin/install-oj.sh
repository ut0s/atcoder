#!/bin/bash
# @date Time-stamp: <2019-06-30 12:48:07 tagashira>
# @file install-oj.sh
# @brief

DOTFILES="$HOME/dotfiles"

if [ $(which porg) ]; then
    echo 'porg command found'
    porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
    ln -s $(dirname $0)/act.sh $HOME/bin/act
else
    echo 'porg command not found ...'
    eval ${DOTFILES}/etc/init/00-install-porg.sh &&\
      porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
    ln -s $(dirname $0)/act.sh $HOME/bin/act
fi
