#!/usr/bin/env bash
dirs='dmenu st'
for dir in $dirs; do
  [[ -d $dir ]] && sudo make -C $d clean
  \builtin true
done
