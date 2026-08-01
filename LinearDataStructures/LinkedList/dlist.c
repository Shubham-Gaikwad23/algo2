#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dlist.h"

/**
 * Initialise DList
 */
void initDList(DList *list) {
    list->head = list->tail = NULL;
}

/**
 * Insert new element to DList
 */
void insert(DList *list, int data, bool sorted) {
    assert(list != NULL);

    // Prepare the new element
    DListElem *newElem = malloc(sizeof(DListElem));
    assert(newElem != NULL);
    newElem->data = data;
    newElem->next = newElem->prev = NULL;

    // Insert into empty list
    if (list->head == NULL) {
        list->head = list->tail = newElem;
        return;
    }

    // Insert into unsorted list at the end
    if (!sorted) {
        list->tail->next = newElem;
        newElem->prev = list->tail;
        list->tail = newElem;
        return;
    }

    // Insert into sorted list, find the place first.
    DListElem *curr = list->head;
    while (curr != NULL && curr->data < data) {
        curr = curr->next;
    }

    // The place is end of list
    if (curr == NULL) {
        list->tail->next = newElem;
        newElem->prev = list->tail;
        list->tail = newElem;
        return;
    }

    // The place is beginning of the list
    if (curr->prev == NULL) {
        curr->prev = newElem;
        newElem->next = curr;
        list->head = newElem;
        return;
    }

    // The place is in the middle of the list
    curr->prev->next = newElem;
    newElem->prev = curr->prev;
    newElem->next = curr;
    curr->prev = newElem;
}

/**
 * Populate Dlist
 */
void populateDList(DList *list, unsigned size) {
    while (size--) {
        insert(list, rand() % 1000, true);
    }
}

/**
 * Print contents
 */
void printDList(DList *list) {
    assert(list != NULL);
    DListElem *e = list->head;
    printf("Doubly linked list contents: ");
    while (e != NULL) {
        printf("%d ", e->data);
        e = e->next;
    }
    printf("\n");
}