#include "list.h"
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  node_t *list = NULL;

  size_t count = 100000; 

  int *test_arr = malloc(sizeof(int) * count);

  for (int i = 0; i < count; ++i)
    test_arr[i] = i;
  shuffle(test_arr, count);

  while (count--)
    list = linkedlist_construct(list, test_arr[count]);

  quick_sort(&list);
  assert(linkedlist_is_ordered(list));

  linkedlist_free(&list);

  free(test_arr);

  return 0;
}


