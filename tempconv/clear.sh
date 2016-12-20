#!/usr/bin/env bash

function del_file {
    if [ -f $1 ]
    then
	rm $1
    fi
}

del_file f2c
del_file c2f
del_file ftable
del_file ctable
del_file tempconv
