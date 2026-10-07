
#include <stdio.h>
#include "linkedlist.h"

int main() {
    node_t *head = NULL;
    push(&head, 5.0);
    push(&head, 11.0);
    push(&head, 10.0);
    add_at(&head, 100.0, 2);
    add_at(&head, 200.0, 3);
    push_front(&head, 67.0);
    push_back(&head, 67.0);
    delete_at(&head, 6);
    //clear(&head);
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    printf("%.2f\n", pop(&head));
    return 0;
}