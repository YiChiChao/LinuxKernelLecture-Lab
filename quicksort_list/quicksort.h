#ifndef QUICKSORT_H
#define QUICKSORT_H

/* This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a circular doubly-linked list to represent the set of queue elements
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct __node {
  struct list_head stack;
  struct __node *next;
  long value;
} node_t;

void linkedlist_add(node_t **list, node_t *node_t);
node_t *linkedlist_tail(node_t **left);
int linkedlist_length(node_t **left);
node_t *linkedlist_construct(node_t *list, int n);
void linkedlist_free(node_t **list);
extern bool linkedlist_is_ordered(node_t *list);
void shuffle(int *array, size_t n);
void quick_sort(node_t **list);

#endif /* QUICKSORT_H */