# Modification Tracker

This file tracks every project modification made during the cleanup process.

## 2026-06-22

### Compile Preparation: Operation File Includes

Files changed:
- `operations_s_p.c`
- `reverse_operations.c`
- `other_operations.c`

Changes made:
- Added `#include "push_swap.h"` to `operations_s_p.c`.
- Added `#include "push_swap.h"` to `reverse_operations.c`.
- Added `#include "push_swap.h"` to `other_operations.c`.

Reason:
- These files use `t_list`, which is declared in `push_swap.h`.
- Without the header include, the files cannot compile correctly.

### Stack Content Swap Fix

File changed:
- `operations_s_p.c`

Changes made:
- Updated `sa` to swap `int content` values directly.
- Updated `sb` to swap `int content` values directly.
- Removed incorrect `int *` dereferencing logic from both functions.

Reason:
- `t_list.content` is currently declared as an `int` in `push_swap.h`.
- The old code treated `content` like an `int *`, which does not match the current structure.

Status:
- Changes applied.
- Compilation not run yet.

### Argument Conversion Fix

File changed:
- `comprobations.c`

Changes made:
- Updated `transform_argv` to read from `argv[0]`.
- Removed the old internal flag-skipping loop from `transform_argv`.
- Updated `stack_a_is_correct` to validate from the first character.
- Added rejection for bare `+` or `-` values.

Reason:
- `main` already passes `&argv[start_index]` into `transform_argv`.
- The previous implementation started at index `1`, so it skipped the first actual number.
- Inputs like `42`, `2 1`, `3 2 1`, and `1 2 3` incorrectly produced `Error`.

Status:
- Changes applied.
- User tested basic inputs.
- Numeric inputs no longer immediately fail with `Error`.
- Sorting behavior still needs algorithm correction.

### Small Stack Sorting Foundation

File changed:
- `push_swap.c`

Changes made:
- Added an `is_sorted` helper.
- Added exact handling for 2-number stacks.
- Added exact handling for 3-number stacks.
- Updated `main` to skip sorting when the stack is already sorted.
- Updated `main` to use the small-stack handlers before strategy selection.

Reason:
- Inputs like `2 1` should sort with a single `sa`.
- Inputs like `1 2 3` should produce no operations.
- The default adaptive path was sending small inputs into generic algorithms that produced unnecessary moves.

Status:
- Changes applied.
- Awaiting user test results.

### Stable Adaptive Sorting Path

File changed:
- `adaptive_sort.c`

Changes made:
- Updated `adaptive_sort` to call `complex_sort` directly.
- Removed adaptive selection between `simple_sort`, `medium_sort`, and `complex_sort`.

Reason:
- The previous adaptive logic could choose `medium_sort`, which is not currently a complete reliable sorting algorithm.
- Larger inputs are now normalized before strategy execution, making `complex_sort` the safest scalable default path.
- This stabilizes default behavior before later optimization work.

Status:
- Changes applied.
- Awaiting user test results.

### Rank Normalization For Larger Inputs

File changed:
- `push_swap.c`

Changes made:
- Added `normalize_values`.
- Updated larger-input sorting path to normalize values before strategy execution.
- Replaces raw values with ranks from `0` to `length - 1` in both the array and stack.

Reason:
- Radix and chunk-based sorting need dense ordered indexes, not raw input values.
- Raw values can include negatives, large gaps, or arbitrary ranges.
- Normalized ranks preserve the same sorted order while making bit-based sorting valid.

Status:
- Changes applied.
- Awaiting user test results.

### Four And Five Number Sorting

File changed:
- `push_swap.c`

Changes made:
- Added `find_min_position`.
- Added `rotate_min_to_top`.
- Added `sort_four_five`.
- Updated `main` to handle stack lengths `4` and `5` before strategy selection.

Reason:
- `push_swap` needs efficient special handling for small inputs.
- The generic/adaptive algorithms were producing unnecessary operations for `4` and `5` numbers.
- The new approach pushes the smallest values to stack B, sorts the remaining three values, then pushes the smallest values back to stack A.

Status:
- Changes applied.
- Awaiting user test results.
