#!/usr/bin/env bash
echo "Number of arguments:" $#
if [ "$#" -ne 1 ]; then
    echo "What would you like to build?"
    exit 1
fi

CPPFLAGS="-std=c++11 -Wall -Werror"
LDFLAGS="-lpqxx -lpq"
cppfiles=*.cpp
headerfiles=*.h

g++ ${CPPFLAGS} -o $1 ${LDFLAGS} ${cppfiles} ${headerfiles}
