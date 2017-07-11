#/bin/bash

find . -iname \*.cpp -exec grep --color -wn -H "$1" \{\} \;
