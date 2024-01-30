#!/bin/sh

echo "Running ./build.sh"
sh ./build.sh

echo "Catalan(4) = 14"
echo "Running ./Catalan 4"
out1=$(./Catalan 4)
# compare output to expected output
if [ "$out1" = "14" ]; then
    echo "==> Test passed"
else
    echo "==> Test failed"
fi

echo "Catalan(10) = 16796"
echo "Running ./Catalan 10"
out1=$(./Catalan 10)
# compare output to expected output
if [ "$out1" = "16796" ]; then
    echo "==> Test passed"
else
    echo "==> Test failed"
fi