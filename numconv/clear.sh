#!/usr/bin/env bash

function del_file {
    if [ -f $1 ]
    then
	rm $1
    fi
}

del_file dec2oct
del_file oct2dec
del_file hex2dec
del_file dec2hex
del_file oct2hex
del_file hex2oct
del_file numconv
