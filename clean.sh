#!/usr/bin/env bash
dirs='st'
for d in $dirs; do
  sudo make clean -C $d
done
