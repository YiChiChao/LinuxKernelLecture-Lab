#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lru.h"
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

long testSearchTime(LRUCache *obj, int key){
    clock_t start, end;
    start = clock();
    lRUCacheGet(obj, key);
    end = clock();
    return (end - start) * 1000000 / CLOCKS_PER_SEC;//us

}
int main()
{
    LRUCache *Cache = lRUCacheCreate(2);
    lRUCachePut(Cache, 1, 1);
    lRUCachePut(Cache, 2, 2);
    printf("Cache Get: %d\n", lRUCacheGet(Cache, 1));
    printf("Cache Get: %d\n", lRUCacheGet(Cache, 2));
    printCache(Cache);
    lRUCachePut(Cache, 3, 3);
    printf("Cache Get: %d\n", lRUCacheGet(Cache, 1));
    printCache(Cache);
    lRUCacheFree(Cache);
    return 0;
}
