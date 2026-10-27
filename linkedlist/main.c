#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    node_t *head = NULL;
    size_t size = 0;
    double *arr = NULL;
    push_front(&head, 10.5);
    push_back(&head, 30.0);
    push_front(&head, 5.0);
    arr = export(head, &size);
    for (size_t i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }

    printf("\n");
    free(arr);
    add_at(&head, 15.0, 1);
    int pos = find(head, 10.5);
    printf("Gefunden bei Index: %d\n", pos);
    delete_at(&head, 2);
    pop_front(&head);
    pop_back(&head);
    clear(&head);
    return 0;
}