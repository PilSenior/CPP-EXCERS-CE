#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}╔════════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║        CPP01 EX04 - FINAL VALIDATION SUITE            ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════════╝${NC}"
echo ""

PASS_COUNT=0
FAIL_COUNT=0

# Test function
test_case() {
    local test_name="$1"
    local expected="$2"
    local actual="$3"
    
    echo -ne "${YELLOW}[TEST]${NC} $test_name ... "
    if [ "$expected" = "$actual" ]; then
        echo -e "${GREEN}✅ PASS${NC}"
        ((PASS_COUNT++))
    else
        echo -e "${RED}❌ FAIL${NC}"
        echo -e "  Expected: $expected"
        echo -e "  Got: $actual"
        ((FAIL_COUNT++))
    fi
}

# Test 1: Basic replacement
echo "Hello World!" > test1.txt
./unnecessary_violence test1.txt "Hello" "Hi" 2>/dev/null
RESULT=$(cat test1.txt.replace)
test_case "Basic replacement" "Hi World!" "$RESULT"

# Test 2: Multiple occurrences
echo -e "foo bar foo baz foo" > test2.txt
./unnecessary_violence test2.txt "foo" "XXX" 2>/dev/null
RESULT=$(cat test2.txt.replace)
test_case "Multiple occurrences" "XXX bar XXX baz XXX" "$RESULT"

# Test 3: Overlapping pattern
echo "aaaaaaa" > test3.txt
./unnecessary_violence test3.txt "aaa" "bb" 2>/dev/null
RESULT=$(cat test3.txt.replace)
test_case "Overlapping pattern (no re-match)" "bbbba" "$RESULT"

# Test 4: Empty file
touch test4.txt
./unnecessary_violence test4.txt "test" "TEST" 2>/dev/null
RESULT=$(wc -c < test4.txt.replace)
test_case "Empty file handling" "0" "$RESULT"

# Test 5: String not found
echo "Hello World" > test5.txt
./unnecessary_violence test5.txt "NOTFOUND" "XXX" 2>/dev/null
RESULT=$(cat test5.txt.replace)
test_case "String not found" "Hello World" "$RESULT"

# Test 6: Empty s1
echo "content" > test6.txt
./unnecessary_violence test6.txt "" "XXX" 2>/dev/null
RESULT=$(cat test6.txt.replace)
test_case "Empty search string" "content" "$RESULT"

# Test 7: Replace with empty
echo "Hello World" > test7.txt
./unnecessary_violence test7.txt "Hello " "" 2>/dev/null
RESULT=$(cat test7.txt.replace)
test_case "Replace with empty string" "World" "$RESULT"

# Test 8: Non-existent file (error handling)
./unnecessary_violence nonexistent.txt "a" "b" 2>&1 | grep -q "Could not open"
if [ $? -eq 0 ]; then
    echo -e "${YELLOW}[TEST]${NC} Non-existent file error ... ${GREEN}✅ PASS${NC}"
    ((PASS_COUNT++))
else
    echo -e "${YELLOW}[TEST]${NC} Non-existent file error ... ${RED}❌ FAIL${NC}"
    ((FAIL_COUNT++))
fi

# Test 9: Wrong arguments
./unnecessary_violence test1.txt 2>&1 | grep -q "Usage"
if [ $? -eq 0 ]; then
    echo -e "${YELLOW}[TEST]${NC} Wrong argument count ... ${GREEN}✅ PASS${NC}"
    ((PASS_COUNT++))
else
    echo -e "${YELLOW}[TEST]${NC} Wrong argument count ... ${RED}❌ FAIL${NC}"
    ((FAIL_COUNT++))
fi

# Test 10: Binary file with null bytes
printf "word1\x00word2" > test10.txt
./unnecessary_violence test10.txt "word1" "REPLACED" 2>/dev/null
RESULT=$(hexdump -C test10.txt.replace | grep -c "REPLACED")
if [ "$RESULT" -gt 0 ]; then
    # Check if null byte is preserved
    NULL_CHECK=$(hexdump -C test10.txt.replace | grep -c "00 77 6f 72 64 32")
    if [ "$NULL_CHECK" -gt 0 ]; then
        echo -e "${YELLOW}[TEST]${NC} Binary file (null byte preservation) ... ${GREEN}✅ PASS${NC}"
        ((PASS_COUNT++))
    else
        echo -e "${YELLOW}[TEST]${NC} Binary file (null byte preservation) ... ${RED}❌ FAIL${NC}"
        ((FAIL_COUNT++))
    fi
else
    echo -e "${YELLOW}[TEST]${NC} Binary file (null byte preservation) ... ${RED}❌ FAIL${NC}"
    ((FAIL_COUNT++))
fi

# Cleanup
rm -f test*.txt test*.txt.replace

echo ""
echo -e "${BLUE}╔════════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║                    TEST SUMMARY                        ║${NC}"
echo -e "${BLUE}╠════════════════════════════════════════════════════════╣${NC}"
echo -e "${GREEN}║  PASSED: $PASS_COUNT tests${NC}"
if [ $FAIL_COUNT -gt 0 ]; then
    echo -e "${RED}║  FAILED: $FAIL_COUNT tests${NC}"
else
    echo -e "${GREEN}║  FAILED: $FAIL_COUNT tests${NC}"
fi
echo -e "${BLUE}╚════════════════════════════════════════════════════════╝${NC}"
echo ""

if [ $FAIL_COUNT -eq 0 ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED! CODE IS READY FOR SUBMISSION! 🎉${NC}"
    exit 0
else
    echo -e "${RED}⚠️  SOME TESTS FAILED. PLEASE FIX THE ISSUES. ⚠️${NC}"
    exit 1
fi
