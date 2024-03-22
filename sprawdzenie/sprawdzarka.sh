cd  
cd /mnt/c/Users/jakub/programowanie/competitve/sprawdzenie

set -e
g++ sprawdzenie.cpp -o sprawdzenie

for((i = 1; i <= 1000; ++i)); do
    cd testy
    cat $i.in > input_file
    mv input_file /mnt/c/Users/jakub/programowanie/competitve/sprawdzenie/

    # cd ..
    # cd out/

    cat $i.out > correctAnswer
    mv correctAnswer /mnt/c/Users/jakub/programowanie/competitve/sprawdzenie/

    # cd ..
    cd ..

    ./sprawdzenie < input_file > myAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
