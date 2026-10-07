
#include <stdio.h>
#include "linkedlist.h"

int main() {
    node_t *head = NULL;
    push(&head, 5.0);
    push(&head, 11.0);
    push(&head, 10.0);
    add_at(&head, 100.0, 2);
    add_at(&head, 200.0, 3);
    add_at(&head, 300.0, 6);
    int index = find(head, 200.0);
    printf("Index: %d\n", index);
    push_front(&head, 67.0);
    push_back(&head, 67.0);
    //delete_at(&head, 6);
    //index = find(head, 300.0);
    //printf("Index: %d\n", index);
    //clear(&head);
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop_back(&head));
    printf("%.2f\n", pop_front(&head));
    return 0;
}