#!/usr/bin/env bash

filename="tempconv"

make ${filename}

ln -f -s `echo ${filename}` f2c
ln -f -s `echo ${filename}` c2f
ln -f -s `echo ${filename}` ftable
ln -f -s `echo ${filename}` ctable
