#include <math.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Parent child index computation
#define PARENT(i) ceil(((double)i / 2.0)) - 1 
#define LCHILD(i) i*2+1
#define RCHILD(i) i*2+2

// Heap Data Structure
typedef struct Heap {
    int *elems;
    unsigned maxSize;
    int top;
}Heap;

/**
 * Swap two integers
 */
void swap(Heap *h, int i, int j) {
    int t = h->elems[i];
    h->elems[i] = h->elems[j];
    h->elems[j] = t;
}

/**
 * Helper for insert.
 * Restore heap property.
 */
void bubbleUp(Heap *h, int top) {
    // Base condition
    if (top == 0) return;

    // Compare with parent and swap
    int pIdx = PARENT(top);
    if (h->elems[pIdx] < h->elems[top]) {
        swap(h, pIdx, top);
        // Recurse upwards
        bubbleUp(h, PARENT(top));
    }
}

/**
 * Insert an element into a Heap
 */
void insert(Heap *h, int elem) {
    assert(h->top + 1 < h->maxSize);
    h->top++;
    h->elems[h->top] = elem;
    bubbleUp(h, h->top);
}

/**
 * Initialise a heap
 */
void init(Heap *h, unsigned size) {
    h->top = -1;
    h->elems = NULL;
    h->elems = malloc(sizeof(int) * size);
    if (h->elems == NULL) assert(false);
    h->maxSize = size;
}

// Print heap
// void printHeap(Heap *h) {
//     printf("Heap contents: ");
//     for (int i = 0; i <= h->top; i++) {
//         printf("%d ", h->elems[i]);
//     }
//     printf("\n");
// }

/**
 * Restore heap property of a heap where root node may violate heap property
 */
void heapify(Heap *h, int rootIdx) {
    if (rootIdx >= (int)ceil(h->top / 2.0)) return; 

    int largest = rootIdx;
    if (h->elems[rootIdx] < h->elems[LCHILD(rootIdx)]) {
        largest = LCHILD(rootIdx);
    }

    if ((RCHILD(rootIdx) <= h->top) &&
        (h->elems[largest] < h->elems[RCHILD(rootIdx)])) {
        largest = RCHILD(rootIdx);
    }

    if (largest != rootIdx) {
        swap(h, largest, rootIdx);
        heapify(h, largest);
    }
}

// Sorting using heap [ O(n log n) ]
void heapSort(Heap *h) {
    while (h->top > 0) {
        swap(h, h->top, 0);
        h->top--;
        heapify(h, 0);
    }
}

// Test helper
int compare_ints(const void *a, const void *b) {
    // Cast generic void pointers to integer pointers and dereference them
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}


int main(void) {
    Heap h;
    const unsigned hSize = 10;
    int testArr[hSize];
    
    init(&h, hSize);
    srand(time(NULL));
    for (int i = 0; i < hSize; i++) {
        int v = rand();
        testArr[i] = v;
        insert(&h, v);
    }

    heapSort(&h);
    h.top = hSize - 1;

    qsort(testArr, hSize, sizeof(int), compare_ints);
    for (int i = 0; i < hSize; i++) {
        assert(testArr[i] == h.elems[i]);
    }
    
    return 0;
}