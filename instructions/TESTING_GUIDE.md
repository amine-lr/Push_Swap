# Push_Swap Testing Guide

## 1. COMPILATION

```bash
cd push_swap
make              # Compile the project
make clean        # Remove object files
make fclean       # Remove everything
make re           # Recompile from scratch
```

## 2. BASIC FUNCTIONALITY TESTS

### Test 1: Simple sorting (3 numbers)
```bash
./push_swap 3 2 1
# Expected: Sequence of operations that sorts the stack
```

### Test 2: Already sorted
```bash
./push_swap 1 2 3 4 5
# Expected: No operations (or very few)
```

### Test 3: Reverse sorted
```bash
./push_swap 5 4 3 2 1
# Expected: Many operations to sort
```

## 3. STRATEGY SELECTION TESTS

### Test --simple strategy
```bash
./push_swap --simple 5 4 3 2 1
# Should use insertion sort O(n²)
```

### Test --medium strategy
```bash
./push_swap --medium 5 4 3 2 1
# Should use chunk sort O(n√n)
```

### Test --complex strategy
```bash
./push_swap --complex 5 4 3 2 1
# Should use radix sort O(n log n)
```

### Test --adaptive strategy (default)
```bash
./push_swap --adaptive 5 4 3 2 1
# Or just: ./push_swap 5 4 3 2 1
# Should select based on disorder
```

## 4. BENCHMARK MODE TESTS

### Test benchmark output
```bash
./push_swap --bench 5 4 3 2 1 2>bench.txt
# Shows operations on stdout
# Shows benchmark stats on stderr (in bench.txt)
```

### Test combined flags
```bash
./push_swap --adaptive --bench 3 2 1 2>bench.txt
./push_swap --bench --complex 4 5 3 1 2
```

## 5. ERROR HANDLING TESTS

### Test duplicate numbers (should error)
```bash
./push_swap 1 2 2 3
# Expected: Error printed to stderr
# Exit code: 1
```

### Test invalid input (should error)
```bash
./push_swap abc def
# Expected: Error printed to stderr
```

### Test integer overflow (should error)
```bash
./push_swap 9999999999999999
# Expected: Error printed to stderr
```

### Test negative numbers (should work)
```bash
./push_swap -5 -3 0 2 1
# Expected: Valid operations
```

### Test mixed signs (should work)
```bash
./push_swap -10 5 0 3 -2
# Expected: Valid operations
```

## 6. EDGE CASES

### Single number (should do nothing)
```bash
./push_swap 42
# Expected: No output
```

### Two numbers (simple case)
```bash
./push_swap 2 1
# Expected: sa (swap)
```

### No arguments (should do nothing)
```bash
./push_swap
# Expected: No output
```

## 7. LARGE DATA TESTS

### Test with 100 random numbers
```bash
# Create file with 100 numbers
python3 -c "import random; print(' '.join(map(str, random.sample(range(10000), 100))))" > nums.txt

# Count operations
./push_swap $(cat nums.txt) | wc -l
# Expected: < 2000 operations (pass), < 1500 (good), < 700 (excellent)
```

### Test with 500 random numbers
```bash
# Create file with 500 numbers
python3 -c "import random; print(' '.join(map(str, random.sample(range(100000), 500))))" > nums.txt

# Count operations
./push_swap $(cat nums.txt) | wc -l
# Expected: < 12000 (pass), < 8000 (good), < 5500 (excellent)
```

## 8. VERIFICATION WITH CHECKER

If you have the official checker:
```bash
# Test a case and pipe to checker
ARG="3 2 1 0 4"; ./push_swap $ARG | ./checker_linux $ARG
# Expected: OK
```

## EXPECTED OUTPUT FORMAT

### Normal output (stdout)
```
sa
pb
ra
rra
pb
pa
```

### Benchmark output (stderr, with --bench flag)
```
=== BENCHMARK ===
Disorder: 80.00%
Strategy: complex (O(n log n))
Total operations: 42
Operation breakdown:
  sa: 0 | sb: 0 | ss: 0
  pa: 8 | pb: 15
  ra: 10 | rb: 0 | rr: 0
  rra: 9 | rrb: 0 | rrr: 0
```

## COMMON ISSUES & FIXES

### Issue: Compilation error - undefined reference
- Solution: Make sure all .c files are in Makefile
- Check: grep "SRCS =" Makefile

### Issue: Segmentation fault
- Solution: Check for NULL pointer dereferences
- Use: valgrind ./push_swap 3 2 1

### Issue: Operations don't match
- Solution: Verify algorithm logic
- Debug: Add printf statements to track state

### Issue: Performance is bad
- Solution: Optimize algorithm or adjust chunk size
- Check: Measure operation count for given inputs

## RECOMMENDED TEST ORDER

1. `make` (compilation)
2. `./push_swap 3 2 1` (basic test)
3. `./push_swap --simple 5 4 3 2 1` (simple algo)
4. `./push_swap --bench 3 2 1 2>bench.txt` (benchmark)
5. `./push_swap 1 2 2 3` (error handling)
6. Large dataset tests (performance)
7. `valgrind ./push_swap 3 2 1` (memory check)
