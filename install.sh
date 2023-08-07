#!/usr/bin/env bash
dirs='dmenu st'
for dir in $dirs; do
  [[ -d $dir ]] && sudo CC=clang make -C $dir clean install
  \builtin true
done
