
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "some_heap.h"

#define KEY_NOT_PRESENT -1

heap_t *heap_create(int capacity) {
    heap_t *heap = malloc(sizeof(heap_t));
    if (heap == NULL) {
        return NULL;
    }
    heap->data = malloc(capacity * sizeof(heap_node_t));
    if (heap->data == NULL) {
        free(heap);
        return NULL;
    }
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_free(heap_t *heap) {
}

unsigned int heap_size(heap_t *heap) { return heap->size; }

unsigned int heap_parent(unsigned int index) {  
    return (index - 1) / 2;
}

unsigned int heap_left_child(unsigned int index) { 
    return 2 * index + 1;
}

unsigned int heap_right_child(unsigned int index) {
    return 2 * index + 2;
 }

unsigned int heap_level(unsigned int index) {
    return (unsigned int) (log2(index + 1));
}

void heap_print(heap_t *heap) {
    for (int ix = 0; ix < heap_size(heap); ix++) {
        printf("%3d - %3d : " HEAP_KEY_FORMAT "\n", heap_level(ix), ix,
               heap->data[ix].key);
    }
    printf("\n");
}

void heap_swap(heap_t *heap, int index1, int index2) {
}

void heap_bubble_up(heap_t *heap, int index) {
}

void heap_bubble_down(heap_t *heap, int index) {
}

void heap_insert(heap_t *heap, heap_key_t key, heap_val_t data) {
    if (heap_size(heap) == heap->capacity) {
        return;
    }

    heap->data[heap_size(heap)].key = key;
    heap->data[heap_size(heap)].value = data;
    heap->size++;

    heap_bubble_up(heap, heap_size(heap) - 1);
}


heap_val_t heap_remove_min(heap_t *heap) {
    if (heap_size(heap) == 0) {
        return (heap_val_t) {.as_int = KEY_NOT_PRESENT};
    }

    heap_val_t min = heap->data[0].value;

    heap->size--;

    // move last element to the root
    heap->data[0] = heap->data[heap_size(heap)];

    // then bubble it down to its correct position
    heap_bubble_down(heap, 0);

    return min;
}
