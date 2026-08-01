#include <assert.h>
#include "dlist.h"

void reverseDList(DList *lst) {
    assert(lst != NULL);

    // Base condition
    if (lst->head == NULL || lst->head == lst->tail) return;

    // Pointer for first and second node
    DListElem *p1, *p2;
    p1 = lst->head;
    p2 = p1->next;
    do {
        // Flip the next and previous pointers of p1
        p1->next = p1->prev;
        p1->prev = p2;

        // Move ahead
        p1 = p2;
        p2 = p2->next;
    } while (p2 != NULL); // Until the p2 reach end of list
    // Finally, flip next and previous pointers of last node
    p1->next = p1->prev;
    p1->prev = NULL;

    // Swap the head and tail pointers
    p1 = lst->head;
    lst->head = lst->tail;
    lst->tail = p1;
}

int main(void) {
    unsigned listSize = 10;
    DList list;
    initDList(&list);
    populateDList(&list, listSize);
    printDList(&list);
    reverseDList(&list);
    printDList(&list);
    return 0;
}
