#!/bin/bash

echo "../replace test_1.txt Bonjour Hello";
../replace test_1.txt "Bonjour" "Hello";
echo "**********************";
cat test_1.txt;
echo "----------------------";
cat test_1.txt.replace;

echo "../replace test_2.txt "Ceci" "ceci"";
../replace test_2.txt "Ceci" "ceci";
echo "**********************";
cat test_2.txt;
echo "----------------------";
cat test_2.txt.replace;

echo "../replace test_2.txt "Ceci" \"\"";
../replace test_2.txt "Ceci" "";
echo "**********************";
cat test_2.txt;
echo "----------------------";
cat test_2.txt.replace;
echo ""

echo "../replace test_3.txt "un" "des"";
../replace test_3.txt "un" "des";
echo "**********************";
cat test_3.txt;
echo "----------------------";
cat test_3.txt.replace;
echo ""

echo "../replace test_4.txt "CecI est un TEst" "Ceci est un test"";
../replace test_4.txt "CecI est un TEst" "Ceci est un test";
echo "**********************";
cat test_4.txt;
echo "----------------------";
cat test_4.txt.replace;
echo ""
echo "../replace test_4.txt "ceci est un test" "Ceci est un test"";
../replace test_4.txt "ceci est un test" "Ceci est un test.";
echo "**********************";
cat test_4.txt;
echo "----------------------";
cat test_4.txt.replace;

echo "../replace test_5.txt "\"\"" "a"";
../replace test_5.txt "" "a";
echo "**********************";
cat test_5.txt;
echo "----------------------";
cat test_5.txt.replace;

echo "../replace test_6.txt "bb" "cc"";
../replace test_6.txt "bb" "cc";
echo "**********************";
cat test_6.txt;
echo "----------------------";
cat test_6.txt.replace;
