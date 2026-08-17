*This project has been created as part of the 42 curriculum by jangonza, molariou*

# 🔄 Push Swap

## 📋 Description

**Push Swap** is a sorting algorithm project from the 42 curriculum. The objective is to sort a stack of integers in ascending order using only a limited set of allowed operations while minimizing the number of operations.

Our implementation analyzes the input by calculating its disorder percentage. Based on this value, it automatically selects the most appropriate sorting strategy:

- 🏃 **Simple algorithm** for small datasets (O(n²))
- ⚡ **Medium algorithm** for moderately disordered inputs (O(n√n))
- 🚀 **Complex algorithm** for large or highly disordered datasets (O(n log n))

## 🎮 Allowed Operations

The program can only use the following operations to manipulate the stacks:

| Operation | Name | Description |
|-----------|------|-------------|
| `sa` | Swap A | Swaps the first two elements at the top of stack_a |
| `sb` | Swap B | Swaps the first two elements at the top of stack_b |
| `ss` | Swap Both | Performs sa and sb simultaneously |
| `pa` | Push A | Takes the first element from stack_b to stack_a |
| `pb` | Push B | Takes the first element from stack_a to stack_b |
| `ra` | Rotate A | Rotates stack_a upwards by one position |
| `rb` | Rotate B | Rotates stack_b upwards by one position |
| `rr` | Rotate Both | Performs ra and rb simultaneously |
| `rra` | Reverse Rotate A | Rotates stack_a downwards by one position |
| `rrb` | Reverse Rotate B | Rotates stack_b downwards by one position |
| `rrr` | Reverse Rotate Both | Performs rra and rrb simultaneously |

## 🧠 Sorting Algorithms

### 🏃 Simple Algorithm (O(n²))

**Strategy:** Repeated minimum extraction (Selection Sort adaptation)

The algorithm repeatedly finds the smallest value in stack_a, rotates the stack until that value reaches the top, and pushes it to stack_b. Once all elements have been moved, they are pushed back to stack_a in sorted order.

**Justification:** The simple algorithm is optimal for small datasets (< 50 elements) because despite its O(n²) complexity, the low constant factors and minimal memory overhead make it faster than more complex approaches on small inputs.

### ⚡ Medium Algorithm (O(n√n))

**Strategy:** Chunk-based sorting with value ranges

After normalizing the input values, the algorithm divides them into value ranges (chunks). Elements belonging to the current chunk are pushed from stack_a to stack_b, while the remaining elements are rotated back. This process is repeated for each chunk range.

**Justification:** The chunk-based approach balances complexity and performance for moderately sized inputs (50-500 elements). By processing elements in value ranges, it reduces rotations and maintains reasonable cache locality.

### 🚀 Complex Algorithm (O(n log n))

**Strategy:** Radix Sort adapted for dual-stack constraints

After normalizing the values to consecutive indices, the algorithm processes the binary representation of each value one bit at a time. For each bit position, elements with a 0 are pushed to stack_b, while elements with a 1 remain in stack_a. After each bit level, all elements are consolidated back into stack_a, and the process repeats for the next bit.

**Justification:** Radix Sort's O(n log n) complexity without comparison operations makes it ideal for large or highly disordered datasets (> 500 elements). The bit-by-bit approach minimizes comparisons and produces optimal results for large inputs.

## 📁 Project Structure

The project is organized into focused source files, each handling specific functionality. This modular design improves readability, simplifies maintenance, and ensures compliance with the 42 Norminette.

| File | Purpose |
|------|---------|
| `main.c` | 🎯 Program entry point, initialization, and main sorting orchestration |
| `init.c` | 🔧 Data structure initialization |
| `dispatcher.c` | 🎛️ Strategy selection and dispatching |
| `parser.c` | 📝 Command-line flag parsing and argument validation |
| `comprobations.c` | ✅ Input validation (duplicates, integer range checks) |
| `cleanup.c` | 🧹 Memory deallocation and cleanup |
| `libft_utils.c` | 🛠️ Basic string/number utility functions |
| `string_utils.c` | 📄 Additional string manipulation utilities |
| `operations_s_p.c` | 🔀 Swap and push operations (sa, sb, ss, pa, pb) |
| `operations.c` | 🔁 Rotate operations (ra, rb, rr) |
| `reverse_operations.c` | 🔄 Reverse rotate operations (rra, rrb, rrr) |
| `other_operations.c` | ⚙️ Additional operation utilities |
| `rotation_utils.c` | 🔧 Helper functions for stack rotation |
| `small_sort.c` | 📊 Sorting for 2-5 element stacks |
| `small_sort_utils.c` | 🎲 Utilities for small sorting |
| `simple_strategy.c` | 🏃 Simple sorting algorithm implementation |
| `medium_strategy.c` | ⚡ Medium sorting algorithm implementation |
| `complex_sort.c` | 🚀 Complex sorting algorithm (Radix Sort) implementation |
| `strategies.c` | 🎛️ Strategy dispatcher and adaptive algorithm |
| `strategy_utils.c` | 🔨 Utility functions for all strategies |
| `benchmark.c` | 📈 Performance measurement and reporting |
| `benchmark_operations.c` | 📊 Detailed operation counting and analysis |
| `push_swap.h` | 📚 Main header file with function declarations and data structures |

## 📋 Instructions

### 🔨 Compilation

Compile the project using:

```bash
make
```

This generates the executable: `push_swap`

### ▶️ Execution

Execute the program by passing the numbers to sort as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

The program outputs the sequence of operations required to sort the stack:

```
pb
pb
rb
pb
rb
pb
pb
rb
pb
rb
rrb
pa
pa
rrb
pa
rrb
pa
pa
pa
```

### 📊 Benchmark Mode

To see performance metrics and operation analysis:

```bash
./push_swap --bench 2 1 3 6 5 8
```

Output:
```
pb
pb
rb
...
=== BENCHMARK ===
Disorder: 13.33%
Strategy: adaptive (adaptive)
Total operations: 19
sa: 0 sb: 0 ss: 0
pa: 6 pb: 6
ra: 0 rb: 4 rr: 0
rra: 0 rrb: 3 rrr: 0
```

## ⚙️ How It Works

1. **📝 Argument Parsing:** The program parses command-line arguments and validates them for duplicates and valid integer ranges.

<<<<<<< HEAD
2. **🎯 Strategy Selection:** Based on the disorder percentage of the input, the adaptive algorithm selects the most efficient sorting strategy:
   - 🏃 Small datasets (< 6 elements) use optimized small sort
   - 💚 Low disorder → Simple algorithm
   - 💛 Medium disorder → Medium algorithm
   - 🔴 High disorder → Complex algorithm
=======
2. **🎯 Strategy Selection:** Based on the disorder percentage of the input, the adaptive algorithm selects the most efficient sorting strategy. We follow the subject thresholds:

   - 🏃 Small datasets (< 6 elements) use optimized small sort (dedicated small-sort routines)
   - 💚 Low disorder: `disorder < 0.2` → **Simple algorithm** (aim: O(n) behavior on nearly-sorted inputs)
   - 💛 Medium disorder: `0.2 ≤ disorder < 0.5` → **Medium algorithm** (O(n√n) target)
   - 🔴 High disorder: `disorder ≥ 0.5` → **Complex algorithm** (O(n log n) target)

   Rationale: the simple strategy is inexpensive on nearly sorted inputs and often produces an effectively linear number of operations when only a few elements are misplaced. The medium chunk-based approach balances rotations and pushes for moderately disordered inputs, while the complex strategy (radix-like) minimizes operations when disorder is high.
>>>>>>> 88cf78f (chore: finalize README logins, add tests, adaptive thresholds, benchmark fixed)

3. **🔢 Normalization:** Values are normalized to consecutive indices (0 to n-1) for efficient processing.

4. **⚡ Sorting:** The selected algorithm executes the sorting operations.

5. **📤 Output:** All operations are printed in order, with optional benchmark statistics.

## 📚 Resources

- 🎥 [Push Swap Visual Guide](https://www.youtube.com/watch?v=OaG81sDEpVk&t=1603s)
- 📖 [Stack Sorting Introduction](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=378s)
- 🔢 [Radix Sort Explanation](https://www.youtube.com/watch?v=4dMsuxfqufg&t=442s)

These resources helped us understand the project requirements and develop effective sorting strategies.

### 🤖 AI Usage

AI was utilized for:
- ✏️ Enhancing and refining documentation to ensure clarity and completeness
- 🌐 Reviewing and improving the English language in the README and code comments
- 📐 Assisting with the organization and structure of project sections for better readability
- 💡 Providing guidance on best practices for algorithm documentation and explanation

## 👥 Contributions

### 👤 jangonza
- 🏗️ Designed the initial project structure
- 🚀 Implemented the program entry point and argument validation
- 🔧 Developed the stack manipulation operations (push, swap, rotate)
- 🔄 Reorganized and refactored the codebase for clarity and efficiency
- ✅ Ensured full compliance with the 42 Norminette
- 📝 Wrote the initial version of the README
- 🔍 Reviewed and refined the complex sorting algorithm (Radix Sort)

### 👤 molariou
- 📊 Implemented the simple sorting algorithm
- 🎯 Implemented the medium sorting algorithm (chunk-based approach)
- 🚀 Implemented the complex sorting algorithm (Radix Sort)
- 🧠 Developed the adaptive algorithm for automatic strategy selection
- 🛠️ Created and maintained the Makefile
- 📚 Designed and organized the project header files
- ✏️ Reviewed and corrected the English documentation throughout the project
<<<<<<< HEAD
=======

## 🔐 Repository Logins (to be completed before final push)

Before the final submission, replace the placeholders below with the official school repository logins for each contributor. The subject requires both learners' logins to be visible in the repository.

- `STUDENT1_LOGIN`: jangonza  <-- replace with your school login
- `STUDENT2_LOGIN`: molariou  <-- replace with your school login

Add the real logins and push the final commit before handing in the project.
>>>>>>> 88cf78f (chore: finalize README logins, add tests, adaptive thresholds, benchmark fixed)
