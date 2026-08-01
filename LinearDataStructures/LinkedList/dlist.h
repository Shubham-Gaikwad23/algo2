#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>
#include <stdbool.h>

// Linked List Data Structure
typedef struct DListElem {
    int data;
    struct DListElem *next;
    struct DListElem *prev;
} DListElem;

typedef struct DList {
    DListElem *head;
    DListElem *tail;
} DList;

/**
 * Insert new element to DList
 */
void insert(DList *list, int data, bool sorted);

/**
 * Populate Dlist
 */
void populateDList(DList *list, unsigned size);

/**
 * Initialise DList
 */
void initDList(DList *list);

/**
 * Print contents
 */
void printDList(DList *list);

#endif