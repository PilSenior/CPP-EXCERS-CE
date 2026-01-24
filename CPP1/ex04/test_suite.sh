#!/bin/bash

echo "========================================="
echo "CPP01 EX04 - COMPREHENSIVE TEST SUITE"
echo "========================================="
echo ""

# Test 1: Normal replacement
echo "TEST 1: Normal string replacement"
echo "---------------------------------"
./unnecessary_violence test_input.txt "Hello" "Hi"
echo "Original file:"
cat test_input.txt | head -3
echo ""
echo "Replaced file:"
cat test_input.txt.replace | head -3
echo ""

# Test 2: Replace with longer string
echo "TEST 2: Replace with longer string"
echo "---------------------------------"
./unnecessary_violence test_input.txt "test" "examination"
cat test_input.txt.replace | head -3
echo ""

# Test 3: Replace with empty string
echo "TEST 3: Replace with empty string"
echo "---------------------------------"
./unnecessary_violence test_input.txt "Hello" ""
cat test_input.txt.replace | head -3
echo ""

# Test 4: Empty s1 (should copy file as-is)
echo "TEST 4: Empty search string"
echo "---------------------------------"
./unnecessary_violence test_input.txt "" "ANYTHING"
cat test_input.txt.replace | head -3
echo ""

# Test 5: String not found
echo "TEST 5: String not found in file"
echo "---------------------------------"
./unnecessary_violence test_input.txt "NOTFOUND" "REPLACED"
cat test_input.txt.replace | head -3
echo ""

# Test 6: Wrong number of arguments
echo "TEST 6: Wrong argument count"
echo "---------------------------------"
./unnecessary_violence test_input.txt "only_two"
echo ""

# Test 7: Non-existent file
echo "TEST 7: Non-existent file"
echo "---------------------------------"
./unnecessary_violence nonexistent.txt "test" "TEST"
echo ""

# Test 8: Overlapping patterns
echo "TEST 8: Overlapping patterns (aaa -> aa)"
echo "---------------------------------"
echo "aaaaaaa" > overlap_test.txt
./unnecessary_violence overlap_test.txt "aaa" "aa"
echo "Original: aaaaaaa"
echo "Result: $(cat overlap_test.txt.replace)"
rm -f overlap_test.txt overlap_test.txt.replace
echo ""

echo "========================================="
echo "ALL TESTS COMPLETED"
echo "========================================="
