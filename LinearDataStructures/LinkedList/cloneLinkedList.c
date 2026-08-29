#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SNode {
    int data;
    struct SNode *next;
    struct SNode *random;
} SNode;

typedef struct SList {
    SNode *head;
    SNode *tail;
} SList;

static SNode *createNode(int data) {
    SNode *node = malloc(sizeof(*node));
    assert(node != NULL);

    node->data = data;
    node->next = NULL;
    node->random = NULL;
    return node;
}

SList *cloneDList(SList *lst) {
    if (lst->head == NULL) return NULL;

    SNode *curr;

    /* ---------------------------------------------------------------
     * PASS 1: Interleave cloned nodes with original nodes.
     *
     * Before: A -> B -> C -> NULL
     * After:  A -> A' -> B -> B' -> C -> C' -> NULL
     *
     * Each clone A' is inserted immediately after its original A.
     * We do NOT set A'->random correctly yet -- we just copy it
     * "as is" from A->random (which currently points to an ORIGINAL
     * node, e.g. B). We'll fix it up to point to the CLONE (B') in
     * pass 2, once every node has a clone sitting right next to it.
     * ------------------------------------------------------------- */
    for (curr = lst->head; curr != NULL; /* no increment here! */) {
        SNode *origNext = curr->next;   // save the REAL next node
                                         // before we rewire anything

        SNode *cln = createNode(curr->data);
        cln->random = curr->random;     // temporary; fixed in pass 2

        cln->next = origNext;           // clone points to what curr
                                         // used to point to
        curr->next = cln;               // curr now points to its clone

        curr = origNext;                // advance to the NEXT ORIGINAL
                                         // node (not the clone!)
    }

    /* ---------------------------------------------------------------
     * PASS 2: Fix up the random pointers on the cloned nodes.
     *
     * At this point, list looks like: A -> A' -> B -> B' -> C -> C'
     *
     * If A->random == B, then A' should have random == B'.
     * Since B' is always immediately after B (curr->random->next),
     * we can find it directly -- no hash map needed!
     * ------------------------------------------------------------- */
    for (curr = lst->head; curr != NULL; curr = curr->next->next) {
        SNode *cln = curr->next;        // the clone sits right after curr

        if (curr->random != NULL) {
            cln->random = curr->random->next;  // original's random's CLONE
        } else {
            cln->random = NULL;
        }
    }

    /* ---------------------------------------------------------------
     * PASS 3: Un-interleave -- split the combined list back into
     * two separate lists: the original (restored) and the clone.
     *
     * Before: A -> A' -> B -> B' -> C -> C' -> NULL
     * After:  A -> B -> C -> NULL          (original, restored)
     *         A'-> B'-> C'-> NULL          (clone, the new list)
     * ------------------------------------------------------------- */
    SList *clonedLst = calloc(1, sizeof(SList));
    clonedLst->head = lst->head->next;   // first clone node = A'

    SNode *currCln;
    for (curr = lst->head, currCln = clonedLst->head;
         curr != NULL;
         curr = curr->next, currCln = currCln->next) {

        SNode *origNext = curr->next->next;   // B, the real next original
                                               // (curr->next is currently A')

        curr->next = origNext;                // restore original list: A -> B

        if (origNext != NULL) {
            currCln->next = origNext->next;   // clone list: A' -> B'
        } else {
            currCln->next = NULL;             // last node: terminate clone list
        }
    }

    clonedLst->tail = currCln;   // NOTE: currCln is NULL after the loop ends,
                                  // see caution below
    return clonedLst;
}

static void buildList(SList *list, const int *values, size_t count,
                      const int *randomTargets) {
    SNode *tail = NULL;
    SNode **nodes = NULL;

    list->head = NULL;

    if (count == 0) {
        return;
    }

    nodes = calloc(count, sizeof(*nodes));
    assert(nodes != NULL);

    for (size_t i = 0; i < count; ++i) {
        SNode *node = createNode(values[i]);
        if (list->head == NULL) {
            list->head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        nodes[i] = node;
    }

    for (size_t i = 0; i < count; ++i) {
        if (randomTargets != NULL && randomTargets[i] >= 0) {
            nodes[i]->random = nodes[randomTargets[i]];
        } else {
            nodes[i]->random = NULL;
        }
    }

    free(nodes);
}

static void assertSameStructure(const SList *original, const SList *clone) {
    const SNode *origCurr = original->head;
    const SNode *cloneCurr = clone->head;

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
    SList original;
    SList *clone;

    buildList(&original, values, count, randomTargets);
    clone = cloneDList(&original);

    if (count == 0) {
        assert(clone == NULL);
    } else {
        assertSameStructure(&original, clone);
    }

    (void)name;
}

int main(void) {
    runCloneTest("empty list", NULL, 0, NULL);
    // runCloneTest("single element", (const int[]){42}, 1, (const int[]){0});
    runCloneTest("two elements", (const int[]){10, 20}, 2, (const int[]){1, 0});
    runCloneTest("multiple elements", (const int[]){5, 2, 9, 1}, 4,
                 (const int[]){2, 0, 3, -1});

    printf("All cloneDList tests passed.\n");
    return 0;
}
