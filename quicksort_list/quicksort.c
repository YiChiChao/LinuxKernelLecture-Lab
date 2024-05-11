#include "quicksort.h"
#include "list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void linkedlist_add(node_t **list, node_t *node_t) {
  node_t->next = *list;
  *list = node_t;
}

node_t *linkedlist_tail(node_t **left) {
  while ((*left) && (*left)->next)
    left = &((*left)->next);
  return *left;
}

int linkedlist_length(node_t **left) {
  int n = 0;
  while (*left) {
    ++n;
    left = &((*left)->next);
  }
  return n;
}

node_t *linkedlist_construct(node_t *list, int n) {
  node_t *node = malloc(sizeof(node_t));
  node->next = list;
  node->value = n;
  // prev and next points to itself
  INIT_LIST_HEAD(&node->stack); 
  return node;
}

void linkedlist_free(node_t **list) {
  node_t *node = (*list)->next;
  while (*list) {
    free(*list);
    *list = node;
    if (node)
      node = node->next;
  }
}

/* Verify if list is order */
bool linkedlist_is_ordered(node_t *list) {
  bool first = true;
  int value;
  while (list) {
    if (first) {
      value = list->value;
      first = false;
    } else {
      if (list->value < value)
        return false;
      value = list->value;
    }
    list = list->next;
  }
  return true;
}

/* shuffle array, only work if n < RAND_MAX */
void shuffle(int *array, size_t n) {
  if (n <= 0)
    return;

  for (size_t i = 0; i < n - 1; i++) {
    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
    int t = array[j];
    array[j] = array[i];
    array[i] = t;
  }
}

void quick_sort(node_t **list) {
  int n = linkedlist_length(list);
  int i = 0;
  node_t *result = NULL, *left = NULL, *right = NULL;
  // point to the first node of the list
  node_t *pivot = *list; 
  int value = pivot->value;
  struct list_head *pivot_ptr = &(pivot->stack);
  while (i >= 0) {
    pivot = list_entry(pivot_ptr, node_t, stack);
    if (pivot->next) {
      value = pivot->value;
      node_t *p = pivot->next;
      pivot->next = NULL;

      while (p) {
        node_t *n = p;
        p = p->next;
        linkedlist_add(n->value > value ? &right : &left, n);
      }
      if (left) {
        list_add_tail(&(left->stack), &(pivot->stack));
        i++;
      }
      if (right) {
        list_add(&(right->stack), &(pivot->stack));
        i++;
        pivot_ptr = pivot_ptr->next;
      }
      left = right = NULL;

    } else {
      pivot_ptr = pivot_ptr->prev;
      list_del_init(&(pivot->stack));
      linkedlist_add(&result, pivot);
      i--;
    }
  }
  *list = result;
}

