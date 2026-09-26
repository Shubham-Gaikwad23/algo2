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

static void assertSameStructure(const List *original, const List *clone,
                                size_t count) {
    Node **originalNodes = count ? malloc(count * sizeof(*originalNodes)) : NULL;
    Node **cloneNodes = count ? malloc(count * sizeof(*cloneNodes)) : NULL;
    const Node *origCurr = original->head;
    const Node *cloneCurr = clone->head;

    assert(original != NULL);
    assert(clone != NULL);
    assert(count == 0 || (originalNodes != NULL && cloneNodes != NULL));

    for (size_t i = 0; i < count; ++i) {
        assert(origCurr != NULL);
        assert(cloneCurr != NULL);
        originalNodes[i] = (Node *)origCurr;
        cloneNodes[i] = (Node *)cloneCurr;
        assert(origCurr->data == cloneCurr->data);
        assert(origCurr != cloneCurr);

        if (origCurr->next == NULL) {
            assert(cloneCurr->next == NULL);
        } else {
            assert(cloneCurr->next != NULL);
        }

        origCurr = origCurr->next;
        cloneCurr = cloneCurr->next;
    }

    assert(origCurr == NULL);
    assert(cloneCurr == NULL);
    assert(original->tail == (count ? originalNodes[count - 1] : NULL));
    assert(clone->tail == (count ? cloneNodes[count - 1] : NULL));

    for (size_t i = 0; i < count; ++i) {
        if (originalNodes[i]->random == NULL) {
            assert(cloneNodes[i]->random == NULL);
        } else {
            size_t targetIndex = 0;
            while (targetIndex < count &&
                   originalNodes[targetIndex] != originalNodes[i]->random) {
                ++targetIndex;
            }
            assert(targetIndex < count);
            assert(cloneNodes[i]->random == cloneNodes[targetIndex]);
        }
    }

    free(originalNodes);
    free(cloneNodes);
}

static void runCloneTest(const char *name, const int *values, size_t count,
                         const int *randomTargets) {
    List original;
    List *clone;

    buildList(&original, values, count, randomTargets);
    clone = cloneList(&original);

    assertSameStructure(&original, clone, count);

    printf("Test name: %s, Result: PASS\n", name);
}

int main(void) {
    runCloneTest("empty list", NULL, 0, NULL);
    runCloneTest("single element with null random",
                 (const int[]){42}, 1, NULL);
    runCloneTest("single element with self random",
                 (const int[]){42}, 1, (const int[]){0});
    runCloneTest("all null random pointers",
                 (const int[]){1, 2, 3}, 3, NULL);
    runCloneTest("all self random pointers",
                 (const int[]){7, 8, 9}, 3, (const int[]){0, 1, 2});
    runCloneTest("duplicate values with distinct random targets",
                 (const int[]){5, 5, 5, 5}, 4, (const int[]){3, 2, 1, 0});
    runCloneTest("all random pointers target one node",
                 (const int[]){2, 4, 6, 8}, 4, (const int[]){2, 2, 2, 2});
    runCloneTest("two elements", (const int[]){10, 20}, 2, (const int[]){1, 0});
    runCloneTest("mixed self, cross, and null random pointers",
                 (const int[]){4, 6, 8, 10}, 4, (const int[]){0, 3, -1, 1});
    runCloneTest("multiple elements", (const int[]){5, 2, 9, 1}, 4,
                 (const int[]){2, 0, 3, -1});

    printf("All cloneList tests passed.\n");
    return 0;
}
