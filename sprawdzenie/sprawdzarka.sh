cd  
cd programowanie/kody/c++/competitve/sprawdzenie/

set -e
g++ sprawdzenie.cpp -o sprawdzenie

for((i = 1; i <= 250001; ++i)); do
    cd testy
    cat wyp$i.in > input_file
    mv input_file ~/programowanie/kody/c++/competitve/sprawdzenie/

    # cd ..
    # cd out/

    cat wyp$i.out > correctAnswer
    mv correctAnswer ~/programowanie/kody/c++/competitve/sprawdzenie/

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
