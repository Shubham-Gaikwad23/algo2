# Heap Revision Notes

- A heap is a complete binary tree stored in an array.
- A max-heap keeps the largest element at the root.
- Insertion adds the new value at the end and then bubbles it upward.
- `bubbleUp()` restores the heap property by swapping with the parent when needed.
- `heapify()` restores the heap property from a node downward by comparing it with its children.
- In a max-heap, the larger child is swapped with the parent if it is bigger.
- Heap sort repeatedly swaps the root with the last element and re-heapifies the remaining part.
- Heaps are mainly used for priority queues and sorting.
- In this implementation, `top` represents the last valid index in the heap.
