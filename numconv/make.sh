#!/usr/bin/env bash

make numconv

ln -f -s numconv dec2oct
ln -f -s numconv oct2dec
ln -f -s numconv hex2dec
ln -f -s numconv dec2hex
ln -f -s numconv oct2hex
ln -f -s numconv hex2oct
