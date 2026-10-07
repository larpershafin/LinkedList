
#include <stdio.h>
#include <time.h>
#include "linkedlist.h"

int main() {
    node_t *head = NULL;
    clock_t start = clock();
    int durchlaufe = 40000;
    for (int i = 0; i < durchlaufe; i++) {
        push(&head, 5.0);
        push(&head, 11.0);
        push(&head, 10.0);
        add_at(&head, 100.0, 2);
        add_at(&head, 200.0, 3);
        add_at(&head, 300.0, 6);
        int index = find(head, 200.0);
        //printf("Index: %d\n", index);
        push_front(&head, 67.0);
        push_back(&head, 67.0);
        //delete_at(&head, 6);
        //index = find(head, 300.0);
        //printf("Index: %d\n", index);
        //clear(&head);
        // printf("%.2f\n", pop(&head));
        // printf("%.2f\n", pop(&head));
        // printf("%.2f\n", pop(&head));
        // printf("%.2f\n", pop(&head));
        // printf("%.2f\n", pop(&head));
        // printf("%.2f\n", pop_back(&head));
        // printf("%.2f\n", pop_front(&head));
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Zeit: %f", time_taken);
    return 0;
}