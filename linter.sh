err=0
test=0

# cppcheck
# run a linter...
LINT_FILES=""
ALL_LINTED_FILES=$(find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -not -name 'build-config.h' -not -path './test/*')
for f in $ALL_LINTED_FILES
do
    test=$((test+1))
    echo "# Check clang-format for $f"
    diff -Naur $f <(clang-format-6.0 $f) > $f.clang-format
    res=$?
    cat $f.clang-format
    if [ $res -ne 0 ]
    then
        LINT_FILES="${LINT_FILES} $f"
        echo "not ok $test - format errors in $f"
        err=$((err+1))
    else
        echo "ok $test - $f passed format check"
    fi
done

if [ "$LINT_FILES" != "" ]
then
    echo
    echo "---------------------------------------------------------"
    echo "To fix all format errors, run"
    echo "    clang-format-6.0 -i $LINT_FILES"
    echo "---------------------------------------------------------"
    echo
fi

test=$((test+1))
# then build docs
echo # doxygen
doxygen docs/Doxyfile 2> doxygen.err
res=$?
cat doxygen.err
doxyfail=0
if [ $res -ne 0 ]
then
    echo "not ok $test - doxygen failed"
    err=$((err+1))
    doxyfail=1
else
    echo "ok $test - doxygen passed"
fi

end_seconds=$(date +%s)

echo "# run cppcheck"
test=$((test+1))
cppcheckfail=0
timestamp=$(date -u +%Y-%m-%dT%H:%M:%SZ)
start_seconds=$(date +%s)

cppcheck -q --enable=all --error-exitcode=1 -i 'test' -i 'test/serializer' --inline-suppr . 2> cppcheck.err
res=$?
cat cppcheck.err
if [ $res -ne 0 ]
then
    echo "not ok $test - cppcheck failed"
    err=$((err+1))
    cppcheckfail=1
else
    echo "ok $test - cppcheck passed" 
fi

echo 1..$test

rm doxygen.err
rm cppcheck.err
find . -name "?*.clang-format" -delete