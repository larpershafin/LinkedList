#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

void push(node_t **head, double info) {
    push_front(head, info);
}

double pop(node_t **head) {
    return pop_front(head);
}

void add_at(node_t **head, double val, size_t index) {
    if (index == 0) {
        push_front(head, val);
        return;
    }
    node_t *curr = *head;
    for (size_t i = 0; curr != NULL && i < index - 1; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Index %zu ist leer\n", index);
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;
}

void push_front(node_t **head, double val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void push_back(node_t **head, double val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

double pop_front(node_t **head) {
    if (*head == NULL) {
        printf("Liste leer\n");
        return 0.0;
    }
    node_t *temp = *head;
    double val = temp->info;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    return val;
}

double pop_back(node_t **head) {
    if (*head == NULL) {
        printf("Liste leer\n");
        return 0.0;
    }
    node_t *curr = *head;

    if (curr->next == NULL) {
        double val = curr->info;
        free(curr);
        *head = NULL;
        return val;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }

    double val = curr->info;
    curr->prev->next = NULL;
    free(curr);
    return val;
}

int find(node_t *head, double val) {
    node_t *curr = head;
    size_t index = 0;

    while (curr != NULL) {
        if (curr->info == val) {
            return index;
        }
        curr = curr->next;
        index++;
    }

    return -1;
}

void delete_at(node_t **head, size_t index) {
    if (*head == NULL) {
        return;
    }
    if (index == 0) {
        pop_front(head);
        return;
    }
    node_t *curr = *head;
    for (size_t i = 0; curr != NULL && i < index; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Index %zu ist ausserhalb\n", index);
        return;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }

    free(curr);
}

double *export(node_t *head, size_t *out_size) {
    if (head == NULL) {
        *out_size = 0;
        return NULL;
    }
    size_t count = 0;
    node_t *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    *out_size = count;
    double *arr = malloc(count * sizeof(double));
    if (arr == NULL) {
        return NULL;
    }
    curr = head;
    for (size_t i = 0; i < count; i++) {
        arr[i] = curr->info;
        curr = curr->next;
    }
    return arr;
}

void clear(node_t **head) {
    if (head == NULL || *head == NULL) {
        return;
    }
    node_t *curr = *head;
    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}