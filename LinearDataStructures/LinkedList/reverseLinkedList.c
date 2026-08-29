#include <assert.h>
#include <stdio.h>
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

static void buildList(DList *list, const int *values, size_t count) {
    initDList(list);
    for (size_t i = 0; i < count; ++i) {
        insert(list, values[i], false);
    }
}

static void assertListValues(DList *list, const int *expected, size_t count) {
    DListElem *curr = list->head;
    size_t i = 0;

    while (curr != NULL && i < count) {
        assert(curr->data == expected[i]);
        curr = curr->next;
        ++i;
    }

    assert(curr == NULL);
    assert(i == count);
}

static void runReverseTest(const char *name, const int *values, size_t count,
                          const int *expected, size_t expectedCount) {
    DList list;

    buildList(&list, values, count);
    reverseDList(&list);
    assertListValues(&list, expected, expectedCount);

    (void)name;
}

int main(void) {
    runReverseTest("empty list", NULL, 0, NULL, 0);
    runReverseTest("single element", (const int[]){42}, 1, (const int[]){42}, 1);
    runReverseTest("two elements", (const int[]){10, 20}, 2, (const int[]){20, 10}, 2);
    runReverseTest("multi element", (const int[]){5, 2, 9, 1}, 4,
                   (const int[]){1, 9, 2, 5}, 4);

    printf("All reverseDList tests passed.\n");
    return 0;
}
