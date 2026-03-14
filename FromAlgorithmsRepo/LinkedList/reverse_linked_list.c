#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define FALSE 0;
#define TRUE 1;

typedef struct node {
    int key;
    struct node *next;
    struct node *prev;
}node;

typedef struct linked_list {
    node *head;
    node *tail;
}linked_list;


inline node * get_node(int key);
void init(linked_list *lst);
void prepend(linked_list *lst, int key);
void append(linked_list *lst, int key);
int delete_head(linked_list *lst, int *key);
void free_list(linked_list *lst);
int insert_at(linked_list *lst, unsigned idx, int key);

node * get_node(int key) {
    node *t = malloc(sizeof(node));
    t->next = t->prev = NULL;
    t->key = key;
    return t;
}

void init(linked_list *lst) {
    lst->head = NULL;
    lst->tail = NULL;
}

void prepend(linked_list *lst, int key) {
    node *t = get_node(key);
    
    if (lst->head == NULL) {
        lst->head = lst->tail = t;
    } else {
        t->next = lst->head;
        lst->head->prev = t;
        lst->head = t;
    }
}

void append(linked_list *lst, int key) {
    node *t = get_node(key);
    
    if (lst->head == NULL) {
        lst->head = lst->tail = t;
    } else {
        lst->tail->next = t;
        t->prev = lst->tail;
        lst->tail = t;
    }
}

int delete_head(linked_list *lst, int *key) {
    if (lst->head == NULL) {
        assert(lst->tail == NULL);
        return FALSE;
    }
    
    // Remember head address and key
    node *t;
    t = lst->head;
    *key = lst->head->key;
    
    // Move head to next node
    lst->head = lst->head->next;
    
    // Free/delete head node's memory
    free(t);
    return TRUE;
}

void free_list(linked_list *lst) {
    node *i, *t;
    
    i = lst->head;
    while (i != NULL) {
        t = i;
        i = i->next;
        free(t);
    }
    
    lst->head = lst->tail = NULL;
}

void print_list(linked_list *lst) {
    node *i;
    printf("Linked list: ");
    for(i = lst->head; i != NULL; i = i->next) {
        printf("%d ", i->key);
    }
    printf("\n");
}

int insert_at(linked_list *lst, unsigned idx, int key) {
    node *i, *j, *t;
    
    // Prepend case
    if (idx == 0) {
        prepend(lst, key);
        return TRUE;
    }

    for (i = lst->head, j = NULL;     // Iterate from head
         i != NULL && idx > 0;           // Until list is exhausted or target index is reached
         j = i, i = i->next, idx--);  // j becomes i, i moves ahead, index decrements

    if (i == NULL) {
        // List index out of range
        if (idx != 0) {
            return FALSE;
        } else { // Append case
            assert(j == lst->tail);
            append(lst, key);
            return TRUE;
        }
    }
    
    t = get_node(key);
    
    // Link t to the list (i & j)
    t->next = i;
    t->prev = j;
    
    // Link i and j to t
    j->next = t;
    i->prev = t;
    
    return TRUE;
}

void reverse(linked_list *lst) {
    node *p, *c, *n;

    for (p = NULL, c = lst->head;
         c != NULL;
         p = c, c = n) {
        
        n = c->next;
        c->next = p;
        c->prev = n;
    }
    
    p = lst->head;
    lst->head = lst->tail;
    lst->tail = p;
}

int main()
{
    linked_list lst;
    int key;
    init(&lst);
    
    assert(lst.head == NULL && lst.tail == NULL);
    assert(!delete_head(&lst, &key));
    print_list(&lst);
    
    append(&lst, 1);
    assert(lst.head->key == 1);
    append(&lst, 2);
    assert(lst.tail->key == 2);
    append(&lst, 3);
    assert(lst.tail->key == 3);
    print_list(&lst);
    
    assert(delete_head(&lst, &key));
    assert(key == 1);
    print_list(&lst);
    
    prepend(&lst, 0);
    assert(lst.head->key == 0);
    print_list(&lst);
    
    free_list(&lst);
    assert(lst.head == NULL && lst.tail == NULL);
    print_list(&lst);
    
    assert(insert_at(&lst, 0, 1));
    assert(lst.head->key == 1);
    assert(lst.tail->key == 1);
    assert(lst.head == lst.tail);
    print_list(&lst);
    
    assert(insert_at(&lst, 1, 2));
    assert(lst.head->key == 1);
    assert(lst.tail->key == 2);
    assert(lst.head != lst.tail);
    print_list(&lst);
    
    assert(insert_at(&lst, 2, 3));
    assert(lst.head->key == 1);
    assert(lst.tail->key == 3);
    assert(lst.head != lst.tail);
    print_list(&lst);
    
    assert(insert_at(&lst, 2, -3));
    assert(lst.tail->key == 3);
    assert(lst.tail->prev->key == -3);
    print_list(&lst);
    
    assert(insert_at(&lst, 0, -5));
    assert(lst.head->key == -5);
    print_list(&lst);
    
    assert(insert_at(&lst, 1, -4));
    assert(lst.head->next->key == -4);
    print_list(&lst);
    
    assert(insert_at(&lst, 3, 0));
    assert(lst.tail->prev->prev->prev->key == 0);
    print_list(&lst);
    
    reverse(&lst);
    print_list(&lst);
    
    free_list(&lst);
    assert(lst.head == NULL && lst.tail == NULL);
    print_list(&lst);

    return 0;
}
