#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
}TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
}BinaryTree;

typedef enum traversal_order {
    IN_ORDER, PRE_ORDER, POST_ORDER
}traversal_order;

void insert(BinaryTree *bt, int key);
void init(BinaryTree *bt);
void free_node(TreeNode *node);
void free_tree(BinaryTree *bt);
void inorder_traversal(TreeNode *n, void (*callback_func)(TreeNode *));
void print_node(TreeNode *node);
void print_tree(BinaryTree *bt, traversal_order order);

static inline TreeNode * make_node(int key) {
    TreeNode *n = malloc(sizeof(TreeNode));
    n->key = key;
    n->left = n->right = n->parent = NULL;
    return n;
}

void init(BinaryTree *bt) {
    bt->root = NULL;
}

void insert(BinaryTree *bt, int key) {
    TreeNode *n = make_node(key);
    if (bt->root == NULL) {
        bt->root = n;
        return;
    }
    
    TreeNode *p, *c;
    c = bt->root;
    n->parent = c->parent;
    while (c != NULL) {
        n->parent = c;
        if (key < c->key) {
            c = c->left;
        } else {
            c = c->right;
        }
    }

    if (key < n->parent->key) {
        n->parent->left = n;
    } else {
        n->parent->right = n;
    }
}

void free_node(TreeNode *node) {
    assert(node != NULL);

    if (node->parent == NULL) {
        goto out;
    }

    if (node->parent->left == node) {
        node->parent->left = NULL;
    } else {
        node->parent->right = NULL;
    }

out:
    free(node);
}

void free_tree(BinaryTree *bt) {
    if (bt->root == NULL) {
        return;
    }

    inorder_traversal(bt->root, &free_node);
    bt->root = NULL;
}

void inorder_traversal(TreeNode *n, void (*callback_func)(TreeNode *)) {
    if (n == NULL) {
        return;
    }

    inorder_traversal(n->left, callback_func);
    (*callback_func)(n);
    inorder_traversal(n->right, callback_func);
}

void preorder_traversal(TreeNode *n, void (*callback_func)(TreeNode *)) {
    if (n == NULL) {
        return;
    }

    (*callback_func)(n);
    preorder_traversal(n->left, callback_func);
    preorder_traversal(n->right, callback_func);
}

void postorder_traversal(TreeNode *n, void (*callback_func)(TreeNode *)) {
    if (n == NULL) {
        return;
    }

    postorder_traversal(n->left, callback_func);
    postorder_traversal(n->right, callback_func);
    (*callback_func)(n);
}

/**
 * Print all keys of given binary tree in order.
 */
void print_tree(BinaryTree *bt, traversal_order order) {
    if (bt->root == NULL) {
        printf("Tree is empty");
        return;
    }

    switch (order) {
    case IN_ORDER:
        printf("Tree content in-order: ");
        inorder_traversal(bt->root, &print_node);
        break;

    case PRE_ORDER:
        printf("Tree content pre-order: ");
        preorder_traversal(bt->root, &print_node);
        break;

    case POST_ORDER:
        printf("Tree content post-order: ");
        postorder_traversal(bt->root, &print_node);
        break;

    default:
        printf("Invalid order: %u", order);
        assert(0);
        break;
    }
    printf("\n");
}

/**
 * Print the key of given node
 */
void print_node(TreeNode *node) {
    assert(node != NULL);
    printf("%d ", node->key);
}

int main() {
    BinaryTree bt;
    init(&bt);
    
    insert(&bt, 5);
    assert(bt.root->key == 5);

    free_tree(&bt);
    assert(bt.root == NULL);

    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        insert(&bt, rand() % 100);
    }

    print_tree(&bt, IN_ORDER);
    print_tree(&bt, PRE_ORDER);
    print_tree(&bt, POST_ORDER);
    
    return 0;
}
