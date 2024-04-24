#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "lru.h"
#define CAPACITY 250
#define NUMMAX 100000

/* typedef struct {
    int capacity;
    int count;
    struct list_head dhead;
    struct hlist_head hhead[];
} LRUCache; */

/*typedef struct {
    int key;
    int value;
    struct hlist_node node;
    struct list_head link;
} LRUNode*/

int hash_size(struct hlist_head *head)
{
    if (!head) {
        return 0;
    }
    int count = 0;
    struct hlist_node *node;
    hlist_for_each(node, head)
    {
        count++;
    }
    return count;
}

void printCache(LRUCache *obj)
{
    struct list_head *cache = &obj->dhead;
    struct list_head *ptr;
    printf("==PRINT CACHE==\n");
    printf("[HEAD]->");
    list_for_each (ptr, cache) {
        LRUNode *node = list_entry(ptr, LRUNode, link);
        int value = node->value;
        printf("[%d]->", value);
    }
    printf("\n===============\n");
    return;
}

/* Aim to test the hit rate and the search time for the LRU mechanism*/

long testSearchTime(LRUCache *obj, int key)
{
    clock_t start, end;
    start = clock();
    lRUCacheGet(obj, key);
    end = clock();
    return (end - start) * 1000000 / CLOCKS_PER_SEC;  // us
}

int main()
{
    srand(time(NULL));

    FILE *outputFile = fopen("multi_search_time_cache250.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }
    LRUCache *Cache = lRUCacheCreate(CAPACITY, CAPACITY);
    for (int i = 0; i < NUMMAX; i++) {
        lRUCachePut(Cache, rand() % NUMMAX, rand() % NUMMAX);
    }
    long totalTestTime = 0;
    for (int i = 0; i < NUMMAX; i++) {
        int keyToSearch = rand() % NUMMAX;
        totalTestTime += lRUCacheGet(Cache, keyToSearch);
    }
    double averageTestTime = (double) totalTestTime / NUMMAX;
     fprintf(outputFile, "HLIST_SIZE : %d AVERAGE SEARCHING TIME : %3f\n",
            CAPACITY, averageTestTime);
    lRUCacheFree(Cache);
    // fprintf(outputFile, "CACHE CAPACITY : %d\n", CAPACITY);
    for (int hlist_size = CAPACITY; hlist_size >= CAPACITY / 100;
         hlist_size -= 10) {
        Cache = lRUCacheCreate(CAPACITY, hlist_size);
        for (int i = 0; i < NUMMAX; i++) {
            lRUCachePut(Cache, rand() % NUMMAX, rand() % NUMMAX);
        }
        long totalSearchTime = 0;
        for (int i = 0; i < NUMMAX; i++) {
            int keyToSearch = rand() % NUMMAX;
            totalSearchTime += lRUCacheGet(Cache, keyToSearch);
        }
        double averageSearchTime = (double) totalSearchTime / NUMMAX;
        fprintf(outputFile, "%3f\n", averageSearchTime);
        lRUCacheFree(Cache);
    }

    /*for(int i = 0; i < CAPACITY; i++){
        fprintf(outputFile, "%d   %d\n", i, hash_size(&Cache->hhead[i]));
    } */
    fclose(outputFile);

    return 0;
}
