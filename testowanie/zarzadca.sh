#!/bin/bash

g++ -O3 -static -o brut brut.cpp -std=c++17
g++ -O3 -static -o wzor wzor.cpp -std=c++17
g++ -O3 -static -o generator generator.cpp -std=c++17

for((i = 1; i > 0; i++));
do
	echo $i > ziarno
	./generator < ziarno > test
	./brut < test > brut.out
	./wzor < test > wzor.out

	if diff -b brut.out wzor.out > /dev/null
	then
		echo -ne "passed: $i \r"
	else
		echo "errrrrror"
		echo "test:"
		cat test

		echo "wynik bruta:"
		cat brut.out

		echo "wynik wzor:"
		cat wzor.out
		break
	fi
done