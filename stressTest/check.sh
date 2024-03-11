#!/bin/bash
cd
cd /home/kuba/programowanie/kody/c++/competitve/stressTest

set -e
g++ lepszy.cpp -o lepszy
g++ brut.cpp -o brut
g++ generator.cpp -o generator
for((i = 1; ; ++i)); do
    ./generator $i > input_file
    ./lepszy < input_file > myAnswer
    ./brut < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer