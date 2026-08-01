# Array Revision Notes

- An array stores elements of the same type in contiguous memory locations.
- Indexing starts from 0 in C/C++ and most programming languages.
- Arrays provide fast access to elements using index-based lookup.
- Common operations include insertion, deletion, traversal, and searching.
- In C, arrays have fixed size, so memory must be allocated carefully.
- The time complexity of access by index is O(1).
- The time complexity of linear search is O(n).
- Arrays are useful for storing sequences and implementing other data structures.

## Problems in this folder

- Missing Number:
  - Given numbers from 0 to n with one value missing, find the missing number.
  - A simple approach is to compute the expected sum and subtract the actual sum.
  - Formula: expected sum = n(n + 1) / 2.

- Row/Column Major Index:
  - Used to map 2D array positions to a 1D memory layout.
  - Row-major formula: index = (row * numCols) + col.
  - Column-major formula: index = (col * numRows) + row.
