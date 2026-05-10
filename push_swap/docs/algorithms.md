# Sorting Algorithms

Small Sort:
- used for <= 5 numbers
- hardcoded optimal moves

Chunk Sort:
- used for medium datasets
- divide indices into chunks
- use least-move rotations

Radix Sort:
- binary radix using normalized indices
- push zeros to b
- rotate ones in a

Adaptive Sort:
- choose algorithm depending on:
  - disorder metric
  - stack size
