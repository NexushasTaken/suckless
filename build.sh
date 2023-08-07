#!/usr/bin/env bash
dirs='st'
for d in $dirs; do
  sudo make clean install -C $d
done
