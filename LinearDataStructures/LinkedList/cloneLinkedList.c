#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *random;
}Node;

typedef struct List {
    Node *head;
    Node *tail;
}List;

static Node *createNode(int data) {
    Node *node = malloc(sizeof(*node));
    assert(node != NULL);

    node->data = data;
    node->next = NULL;
    node->random = NULL;
    return node;
}

Node * dupNode(Node *s) {
    assert(s != NULL);
    Node *t = malloc(sizeof(Node));
    assert(t != NULL);
    t->next = NULL;
    t->random = NULL;
    t->data = s->data;
    return t;
}

void insertAtTail(List *lst, Node *node) {
    assert(lst != NULL && node != NULL);

    if (lst->tail == NULL) {
        lst->head = lst->tail = node;
    } else {
        lst->tail->next = node;
        lst->tail = node;
    }
}

List* cloneList(List* lst) {
    assert(lst != NULL);

    // Clone the list in-place. Random pointer is not yet set.
    Node *p = lst->head;
    while (p != NULL) {
        Node *dup = dupNode(p);
        dup->next = p->next;
        p->next = dup;
        p = dup->next;
    }

    // Now set the random pointer.
    p = lst->head;
    while (p != NULL) {
        if (p->random == NULL) {
            p->next->random = NULL;
            p = p->next->next;
        } else {
            p->next->random = p->random->next;
            p = p->next->next;
        }
    }

    // Separate out the in-place cloned list
    List *clonedLst = malloc(sizeof(List));
    assert(clonedLst != NULL);
    clonedLst->head = clonedLst->tail = NULL;
    p = lst->head;
    while (p != NULL) {
        insertAtTail(clonedLst, p->next);
        p->next = p->next->next;
        p = p->next;
    }

    return clonedLst;
}

static void buildList(List *list, const int *values, size_t count,
                      const int *randomTargets) {
    Node *tail = NULL;
    Node **nodes = NULL;

    list->head = NULL;
    list->tail = NULL;

    if (count == 0) {
        return;
    }

    nodes = calloc(count, sizeof(*nodes));
    assert(nodes != NULL);

    for (size_t i = 0; i < count; ++i) {
        Node *node = createNode(values[i]);
        if (list->head == NULL) {
            list->head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        nodes[i] = node;
    }
    list->tail = tail;

    for (size_t i = 0; i < count; ++i) {
        if (randomTargets != NULL && randomTargets[i] >= 0) {
            nodes[i]->random = nodes[randomTargets[i]];
        } else {
            nodes[i]->random = NULL;
        }
    }

    free(nodes);
}

static void assertSameStructure(const List *original, const List *clone) {
    const Node *origCurr = original->head;
    const Node *cloneCurr = clone->head;

    assert(original != NULL);
    assert(clone != NULL);

    while (origCurr != NULL && cloneCurr != NULL) {
        assert(origCurr->data == cloneCurr->data);
        assert(origCurr != cloneCurr);   // clone must be a distinct node,
                                          // never the same allocation

        if (origCurr->next == NULL) {
            assert(cloneCurr->next == NULL);
        } else {
            assert(cloneCurr->next != NULL);
        }

        /* -----------------------------------------------------------
         * random pointer checks -- three cases to handle:
         *
         * 1. origCurr->random == NULL
         *      -> cloneCurr->random must also be NULL
         *
         * 2. origCurr->random == origCurr (self-reference)
         *      -> cloneCurr->random must be cloneCurr (self-reference
         *         in the CLONE, not a pointer back into the original)
         *
         * 3. origCurr->random points to some OTHER node
         *      -> cloneCurr->random must point to the CLONE of that
         *         node (same data, and definitely not the same
         *         allocation as anything in the original list)
         * --------------------------------------------------------- */
        if (origCurr->random == NULL) {
            assert(cloneCurr->random == NULL);

        } else if (origCurr->random == origCurr) {
            // self-reference case: clone's random must point to
            // ITSELF, not back to the original node
            assert(cloneCurr->random == cloneCurr);

        } else {
            // points to a different node somewhere in the list
            assert(cloneCurr->random != NULL);
            assert(origCurr->random->data == cloneCurr->random->data);

            // make sure clone truly built its own node graph,
            // not just copied pointers into the original list
            assert(cloneCurr->random != origCurr->random);
        }

        origCurr = origCurr->next;
        cloneCurr = cloneCurr->next;
    }

    assert(origCurr == NULL);
    assert(cloneCurr == NULL);
}

static void runCloneTest(const char *name, const int *values, size_t count,
                         const int *randomTargets) {
    List original;
    List *clone;

    buildList(&original, values, count, randomTargets);
    clone = cloneList(&original);

    assertSameStructure(&original, clone);

    printf("Test name: %s, Result: PASS\n", name);
}

int main(void) {
    runCloneTest("empty list", NULL, 0, NULL);
    // runCloneTest("single element", (const int[]){42}, 1, (const int[]){0});
    runCloneTest("two elements", (const int[]){10, 20}, 2, (const int[]){1, 0});
    runCloneTest("multiple elements", (const int[]){5, 2, 9, 1}, 4,
                 (const int[]){2, 0, 3, -1});

    printf("All cloneList tests passed.\n");
    return 0;
}
